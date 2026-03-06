// Fill out your copyright notice in the Description page of Project Settings.


#include "HCP_PCG/Filters/hcp_vpcg_surface_filter.h"

// Copyright Epic Games, Inc. All Rights Reserved.

//#include "Elements/PCGDensityFilter.h"

#include "Data/PCGSpatialData.h"
#include "PCGCustomVersion.h"
#include "Data/PCGBasePointData.h"
#include "Helpers/PCGAsync.h"
#include "PCGContext.h"

#include "HCP_PCG/Objects/hcp_voxel_storage.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(hcp_vpcg_surface_filter)

#define LOCTEXT_NAMESPACE "HCP_VPCGSurfaceFilter"

FPCGElementPtr UHCP_VPCGSurface_Filter::CreateElement() const
{
	return MakeShared<FHCP_VPCGSurfaceFilterElement>();
}


bool hcp_surface_functions_class::is_voxel_surface_vertex(FIntVector3 voxel_coordinate, FIntVector3 matrix_dimension, FConstPCGPointValueRanges &hcp_vpcg_grid_values) {
	if (hcp_vpcg_grid_values.DensityRange.Num() < 1) return false;

	int neighbour;
	int valid_neighbours = 0;

	hcp_vpcg_voxel_automata_functions voxel_automata_hcp_functions;

	// Need to also cater for a valid voxel threshold value 
	for (neighbour = 0; neighbour < NUMBER_HCP_NEIGHBOURS; neighbour++) {
		if (voxel_automata_hcp_functions.get_voxel_neighbour_state(hcp_vpcg_grid_values, neighbour, voxel_coordinate.X, voxel_coordinate.Y, voxel_coordinate.Z, matrix_dimension) != INVALID_VOXEL_VALUE)
			valid_neighbours++;
	}

	if (valid_neighbours == NUMBER_HCP_NEIGHBOURS) // voxel is an interior voxel
		return false;
	else
		return true;
}


bool FHCP_VPCGSurfaceFilterElement::ExecuteInternal(FPCGContext* Context) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FHCP_VPCGSurfaceFilterElement::Execute);

	const UHCP_VPCGSurface_Filter* Settings = Context->GetInputSettings<UHCP_VPCGSurface_Filter>();
	check(Settings);

	TArray<FPCGTaggedData> Inputs = Context->InputData.GetInputsByPin(PCGPinConstants::DefaultInputLabel);
	TArray<FPCGTaggedData>& Outputs = Context->OutputData.TaggedData;

	const bool bInvertFilter = Settings->bInvertFilter;
	const float LowerBound = Settings->LowerBound;
	const float UpperBound = Settings->UpperBound;
#if WITH_EDITOR
	const bool bKeepZeroDensityPoints = Settings->bKeepZeroDensityPoints;
#else
	const bool bKeepZeroDensityPoints = false;
#endif

	const float MinBound = FMath::Min(LowerBound, UpperBound);
	const float MaxBound = FMath::Max(LowerBound, UpperBound);

	const bool bNoResults = (MaxBound <= 0.0f && !bInvertFilter) || (MinBound == 0.0f && MaxBound >= 1.0f && bInvertFilter);
	const bool bTrivialFilter = (MinBound <= 0.0f && MaxBound >= 1.0f && !bInvertFilter) || (MinBound == 0.0f && MaxBound == 0.0f && bInvertFilter);

	if (bNoResults && !bKeepZeroDensityPoints)
	{
		PCGE_LOG(Verbose, LogOnly, LOCTEXT("AllInputsRejected", "Skipped - all inputs rejected"));
		return true;
	}

	// +++++++++++++++ Begin Added Code
	hcp_voxel_storage voxel_object_data;

	FIntVector3 voxel_volume_dim = voxel_object_data.calc_voxel_volume_dimensions(Settings->GridExtents, Settings->CellSize);
	// +++++++++++++++ End Added Code

	// TODO: embarassingly parallel loop
	for (const FPCGTaggedData& Input : Inputs)
	{
		FPCGTaggedData& Output = Outputs.Add_GetRef(Input);

		if (!Input.Data || Cast<UPCGSpatialData>(Input.Data) == nullptr)
		{
			PCGE_LOG(Error, GraphAndLog, LOCTEXT("InvalidInputData", "Invalid input data"));
			continue;
		}

		// Skip processing if the transformation is trivial
		if (bTrivialFilter)
		{
			PCGE_LOG(Verbose, LogOnly, LOCTEXT("TrivialFilter", "Skipped - trivial filter"));
			continue;
		}

		const UPCGBasePointData* OriginalData = Cast<UPCGSpatialData>(Input.Data)->ToBasePointData(Context);

		if (!OriginalData)
		{
			PCGE_LOG(Error, GraphAndLog, LOCTEXT("NoPointDataInInput", "Unable to get point data from input"));
			continue;
		}

		UPCGBasePointData* FilteredData = FPCGContext::NewPointData_AnyThread(Context);

		FPCGInitializeFromDataParams InitializeFromDataParams(OriginalData);

		// Do not inherit because we are going to filter out some points
		InitializeFromDataParams.bInheritSpatialData = false;
		FilteredData->InitializeFromDataWithParams(InitializeFromDataParams);

		Output.Data = FilteredData;

		auto InitializeFunc = [FilteredData, OriginalData]()
			{
				FilteredData->SetNumPoints(OriginalData->GetNumPoints(), /*bInitializeValues=*/false);
				FilteredData->AllocateProperties(OriginalData->GetAllocatedProperties() | EPCGPointNativeProperties::Density);
				FilteredData->CopyUnallocatedPropertiesFrom(OriginalData);
			};

		auto AsyncProcessRangeFunc = [FilteredData, OriginalData, MinBound, MaxBound, bInvertFilter, bKeepZeroDensityPoints, voxel_volume_dim](int32 StartReadIndex, int32 StartWriteIndex, int32 Count)
			{
				//const FConstPCGPointValueRanges ReadRanges(OriginalData); // As per usual const is a cause of problems passing variable values to functions as a reference
				FConstPCGPointValueRanges ReadRanges(OriginalData);
				FPCGPointValueRanges WriteRanges(FilteredData, /*bAllocate=*/false);

				int32 NumWritten = 0;

				// ***************** Begin Added Code
				hcp_voxel_storage           voxel_object_data;
				FIntVector3                 voxel_coordinate;
				hcp_surface_functions_class hcp_surface_functions;
				// ***************** End Added Code

				for (int32 ReadIndex = StartReadIndex; ReadIndex < StartReadIndex + Count; ++ReadIndex)
				{
					const int32 WriteIndex = StartWriteIndex + NumWritten;
					const float ReadDensity = ReadRanges.DensityRange[ReadIndex];
					//const bool bInRange = (ReadDensity >= MinBound && ReadDensity <= MaxBound);

					// ***************** Begin Added Code
					bool bInRange = false; // ++++

					if (ReadDensity > -1) {
						FIntVector3 hcp_grid_dim = voxel_object_data.get_matrix_coordinate(ReadIndex, voxel_volume_dim);
						voxel_coordinate = voxel_object_data.get_matrix_coordinate(ReadIndex, voxel_volume_dim);

						if (hcp_surface_functions.is_voxel_surface_vertex(voxel_coordinate, voxel_volume_dim, ReadRanges)) {

							bInRange = true;
						}
					}

					// ***************** End Added Code

					if (bInRange != bInvertFilter)
					{
						WriteRanges.SetFromValueRanges(WriteIndex, ReadRanges, ReadIndex);
						WriteRanges.DensityRange[WriteIndex] = ReadRanges.DensityRange[ReadIndex];
						++NumWritten;
					}
#if WITH_EDITOR
					else if (bKeepZeroDensityPoints)
					{
						WriteRanges.SetFromValueRanges(WriteIndex, ReadRanges, ReadIndex);
						WriteRanges.DensityRange[WriteIndex] = 0.f;
						++NumWritten;
					}
#endif
				}

				return NumWritten;
			};

		auto MoveDataRangeFunc = [FilteredData](int32 RangeStartIndex, int32 MoveToIndex, int32 NumElements)
			{
				FilteredData->MoveRange(RangeStartIndex, MoveToIndex, NumElements);
			};

		auto FinishedFunc = [FilteredData](int32 NumWritten)
			{
				FilteredData->SetNumPoints(NumWritten);
			};

		FPCGAsyncState* AsyncState = Context ? &Context->AsyncState : nullptr;
		FPCGAsync::AsyncProcessingRangeEx(
			AsyncState,
			OriginalData->GetNumPoints(),
			InitializeFunc,
			AsyncProcessRangeFunc,
			MoveDataRangeFunc,
			FinishedFunc,
			/*bEnableTimeSlicing=*/false);

		PCGE_LOG(Verbose, LogOnly, FText::Format(LOCTEXT("GenerationInfo", "Generated {0} points out of {1} source points"), FilteredData->GetNumPoints(), OriginalData->GetNumPoints()));
	}

	return true;
}

#undef LOCTEXT_NAMESPACE
