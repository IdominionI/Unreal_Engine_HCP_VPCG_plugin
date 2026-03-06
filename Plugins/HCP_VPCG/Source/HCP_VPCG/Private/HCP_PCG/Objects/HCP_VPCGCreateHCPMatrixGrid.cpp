// Fill out your copyright notice in the Description page of Project Settings.


//#include "HCP_PCG/Objects/hcp_voxel.h"
#include "HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h"

#include "PCGComponent.h"
#include "PCGContext.h"
#include "Data/PCGPointArrayData.h"
#include "Elements/PCGCreatePoints.h"
#include "Helpers/PCGAsync.h"
#include "Helpers/PCGHelpers.h"
#include "Helpers/PCGSettingsHelpers.h"

#include "GameFramework/Actor.h"

#include "HCP_PCG/Objects/hcp_voxel_storage.h"

//#include UE_INLINE_GENERATED_CPP_BY_NAME(hcp_voxel)
#include UE_INLINE_GENERATED_CPP_BY_NAME(HCP_VPCGCreateHCPMatrixGrid)

#define LOCTEXT_NAMESPACE "HCP_VPCG"
#define PCGEX_NAMESPACE CreateBuilder_hcp_vpcg

UHCP_VPCGCreateHCPGridSettings::UHCP_VPCGCreateHCPGridSettings()
{
	if (PCGHelpers::IsNewObjectAndNotDefault(this))
	{
		PointSteepness = 1.0f;
	}
}


void UHCP_VPCGCreateHCPGridSettings::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
		if (GridPivot_DEPRECATED != EHCP_VPCGGridPivot::Global)
		{
			CoordinateSpace = static_cast<EPCGCoordinateSpace>(static_cast<int8>(GridPivot_DEPRECATED));
			GridPivot_DEPRECATED = EHCP_VPCGGridPivot::Global;
		}
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
#endif
}

TArray<FPCGPinProperties> UHCP_VPCGCreateHCPGridSettings::InputPinProperties() const
{
	return TArray<FPCGPinProperties>();
}

FPCGElementPtr UHCP_VPCGCreateHCPGridSettings::CreateElement() const
{
	return MakeShared<FHCP_VPCGCreatePointsGridElement>();
}

bool FHCP_VPCGCreatePointsGridElement::ExecuteInternal(FPCGContext* Context) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FPCGCreatePointsGridElement::Execute);
	check(Context);

	if (!Context->ExecutionSource.IsValid())
	{
		return true;
	}

	const UHCP_VPCGCreateHCPGridSettings* Settings = Context->GetInputSettings<UHCP_VPCGCreateHCPGridSettings>();
	check(Settings);

	// Original code commented out because no HCP points are to be culled
	// Used for culling, regardless of generation coordinate space
	//const UPCGSpatialData* CullingShape = Settings->bCullPointsOutsideVolume ? Cast<UPCGSpatialData>(Context->ExecutionSource->GetExecutionState().GetSelfData()) : nullptr;
	//const UPCGSpatialData* CullingShape = false;

	//// Early out if the culling shape isn't valid
	//if (!CullingShape && Settings->bCullPointsOutsideVolume)
	//{
	//	PCGE_LOG(Error, GraphAndLog, LOCTEXT("CannotCullWithoutAShape", "Unable to cull since the supporting actor has no data."));
	//	return true;
	//}

	FTransform LocalTransform = Settings->CoordinateSpace == EPCGCoordinateSpace::World ? FTransform::Identity : Context->ExecutionSource->GetExecutionState().GetTransform();

	if (Settings->CoordinateSpace == EPCGCoordinateSpace::OriginalComponent)
	{
		UPCGComponent* SourceComponent = Cast<UPCGComponent>(Context->ExecutionSource.Get());
		if (SourceComponent)
		{
			check(SourceComponent->GetOriginalComponent() && SourceComponent->GetOriginalComponent()->GetOwner());
			LocalTransform = SourceComponent->GetOriginalComponent()->GetOwner()->GetActorTransform();
		}
	}

	// Reset the scale on the local transform since we don't want to derive the points scale from the referential
	LocalTransform.SetScale3D(FVector::One());

	//if (Settings->CellSize.X <= 0.0 || Settings->CellSize.Y <= 0.0 || Settings->CellSize.Z <= 0.0)// Original code 
	if (Settings->CellSize <=0.0) // Modification : In defining a HCP grid The grid cell size is of one single value
	{
		PCGE_LOG(Warning, GraphAndLog, LOCTEXT("InvalidCellDataInput", "CellSize must not be less than 0"));
		return true;
	}

	if (Settings->GridExtents.X < 0.0 || Settings->GridExtents.Y < 0.0 || Settings->GridExtents.Z < 0.0)
	{
		PCGE_LOG(Warning, GraphAndLog, LOCTEXT("InvalidGridDataInput", "GridExtents must not be less than 0"));
		return true;
	}

	FVector GridExtents = Settings->GridExtents;
	const float& CellSize = Settings->CellSize;

	// ++++++++++++++++++++ Begin Added/Modified Code +++++++++
	hcp_voxel_storage hcp_vs;

	FIntVector3 voxel_volume_dim = hcp_vs.calc_voxel_volume_dimensions(GridExtents, CellSize);

	int32 PointCountX = voxel_volume_dim.X;
	int32 PointCountY = voxel_volume_dim.Y;
	int32 PointCountZ = voxel_volume_dim.Z;

	int64 NumIterations64 = hcp_vs.calculate_voxel_matrix_data_size(voxel_volume_dim.X, voxel_volume_dim.Y, voxel_volume_dim.Z);
	// ++++++++++++++++++++ END  Added/Modified Code +++++++++

	if (NumIterations64 <= 0)
	{
		PCGE_LOG(Error, GraphAndLog, LOCTEXT("InvalidNumberOfIterations", "The number of iterations produced cannot be less than or equal to 0."));
		return true;
	}

	// Retained original point count/offset as offset can be used as a future node input to be used to translate the HCP grid origin and points location from point (0,0,0)
	// Adjust point count/offset with respect to the Culling Shape bounding box if any.
	int32 PointOffsetX = 0;
	int32 PointOffsetY = 0;
	int32 PointOffsetZ = 0;

	if (NumIterations64 >= MAX_int32)
	{
		PCGE_LOG(Error, GraphAndLog, LOCTEXT("Overflow_int32", "The number of iterations produced is larger than what a 32-bit integer can hold."));
		return true;
	}

	if (PCGFeatureSwitches::CVarCheckSamplerMemory.GetValueOnAnyThread() && FPlatformMemory::GetStats().AvailablePhysical < sizeof(FPCGPoint) * NumIterations64)
	{
		PCGE_LOG(Error, GraphAndLog, LOCTEXT("MemoryOverflow", "The number of iterations produced is larger than available memory."));
		return true;
	}

	const int32 NumIterations = static_cast<int32>(NumIterations64);

	UPCGBasePointData* PtData = nullptr;

	auto InitFunc = [Context, Settings, CellSize, NumIterations, &PtData]()
		{
			PtData = FPCGContext::NewPointData_AnyThread(Context);

			check(PtData);

			PtData->SetNumPoints(NumIterations);

			// Set Steepness
			PtData->SetSteepness(Settings->PointSteepness);
			if (Settings->bSetPointsBounds)
			{
				PtData->SetExtents({ CellSize * 0.5,CellSize * 0.5,CellSize * 0.5 });
			}

			PtData->AllocateProperties(EPCGPointNativeProperties::Transform | EPCGPointNativeProperties::Seed);
		};

	auto ProcessFunc = [Settings, &PointCountX, &PointCountY, &PointCountZ, &PointOffsetX, &PointOffsetY, &PointOffsetZ, &CellSize, &GridExtents, &LocalTransform, &PtData](int32 StartIndex, int32 StartWriteIndex, int32 Count)
		{
			TPCGValueRange<FTransform> TransformRange = PtData->GetTransformValueRange(/*bAllocate=*/false);
			TPCGValueRange<int32> SeedRange = PtData->GetSeedValueRange(/*bAllocate=*/false);

			ensure(TransformRange.Num() == SeedRange.Num() && (StartWriteIndex + Count) <= TransformRange.Num());

			hcp_voxel_storage voxel_object_data;

			int32 NumWritten = 0;
			for (int32 Index = StartIndex; Index < StartIndex + Count; ++Index)
			{

				FIntVector3 hcp_Voxel_Coord = voxel_object_data.get_matrix_coordinate(Index, { PointCountX, PointCountY, PointCountZ });

				FVector voxel_cartesian_coord = voxel_object_data.get_voxel_cartesian_coordinate(hcp_Voxel_Coord, CellSize);

				double XCoordinate = voxel_cartesian_coord.X + PointOffsetX;
				double YCoordinate = voxel_cartesian_coord.Y + PointOffsetY;
				double ZCoordinate = voxel_cartesian_coord.Z + PointOffsetZ;

				// If the extends are smaller than the point, set point to origin
				if (GridExtents.X < CellSize / 2.0)
				{
					XCoordinate = 0.0;
				}

				if (GridExtents.Y < CellSize / 2.0)
				{
					YCoordinate = 0.0;
				}

				if (GridExtents.Z < CellSize / 2.0)
				{
					ZCoordinate = 0.0;
				}

				//FTransform PointTransform = FTransform(FVector((CellSize.X * XCoordinate) - GridExtents.X, (CellSize.Y * YCoordinate) - GridExtents.Y, (CellSize.Z * ZCoordinate) - GridExtents.Z));
				//FTransform PointTransform = FTransform(FVector((CellSize * XCoordinate) - GridExtents.X, (CellSize * YCoordinate) - GridExtents.Y, (CellSize * ZCoordinate) - GridExtents.Z));
				FTransform PointTransform = FTransform(FVector(XCoordinate,YCoordinate,ZCoordinate));

				if (Settings->CoordinateSpace == EPCGCoordinateSpace::LocalComponent || Settings->CoordinateSpace == EPCGCoordinateSpace::OriginalComponent)
				{
					PointTransform *= LocalTransform;
				}

				// Original code commented out because no HCP points are to be culled
				// Discards points outside of the volume
				//if (!CullingShape || (CullingShape->GetDensityAtPosition(PointTransform.GetLocation()) > 0.0f))
				//{
				const int32 WriteIndex = StartWriteIndex + NumWritten;

// Debuggin code
//UE_LOG(LogTemp, Error, TEXT("Valid :: WriteIndex %i > TransformRange %i :: NumWritten = %i : StartIndex = %i : StartWriteIndex = %i : Count = %i : Index = %i "), WriteIndex, TransformRange.Num(), NumWritten, StartIndex, StartWriteIndex, Count, Index);
//UE_LOG(LogTemp, Error, TEXT("Voxel Coord :: Index =  %i : hcp_Voxel_Coord X = %i :: hcp_Voxel_Coord Y = %i : hcp_Voxel_Coord Z = %i : Voxel_Cart_Coord X = %f :: Voxel_Cart_Coord Y = %f : Voxel_Cart_Coord Z = %f"), Index, hcp_Voxel_Coord.X, hcp_Voxel_Coord.Y, hcp_Voxel_Coord.Z, voxel_cartesian_coord.X, voxel_cartesian_coord.Y, voxel_cartesian_coord.Z);
//UE_LOG(LogTemp, Error, TEXT("Coord ::  XCoordinate = %f :: YCoordinate = %f : ZCoordinate = %f"), XCoordinate, YCoordinate, ZCoordinate);


				TransformRange[WriteIndex] = PointTransform;
				SeedRange[WriteIndex] = PCGHelpers::ComputeSeedFromPosition(PointTransform.GetLocation());
				++NumWritten;
				//}
			}

			return NumWritten;
		};

	auto MoveRangeFunc = [&PtData](int32 RangeStartIndex, int32 MoveToIndex, int32 NumElements)
		{
			PtData->MoveRange(RangeStartIndex, MoveToIndex, NumElements);
		};

	auto FinishFunc = [&PtData](int32 NumWritten)
		{
			PtData->SetNumPoints(NumWritten);
		};


UE_LOG(LogTemp, Error, TEXT("NumIterations %i"), NumIterations);

	FPCGAsync::AsyncProcessingRangeEx(&Context->AsyncState, NumIterations, InitFunc, ProcessFunc, MoveRangeFunc, FinishFunc, false);

	TArray<FPCGTaggedData>& Outputs = Context->OutputData.TaggedData;
	FPCGTaggedData& Output = Outputs.Emplace_GetRef();
	Output.Data = PtData;

	return true;
}

UPCGData* GetDependenciesData(IPCGGraphExecutionSource* InExecutionSource, EPCGCoordinateSpace InCoordinateSpace, bool bInCullPointsOutsideVolume)
{
	if (InExecutionSource)
	{
		if (bInCullPointsOutsideVolume || InCoordinateSpace == EPCGCoordinateSpace::LocalComponent)
		{
			return InExecutionSource->GetExecutionState().GetSelfData();
		}
		else if (InCoordinateSpace == EPCGCoordinateSpace::OriginalComponent)
		{
			const UPCGComponent* SourceComponent = Cast<UPCGComponent>(InExecutionSource);
			if (SourceComponent)
			{
				return SourceComponent->GetOriginalActorPCGData();
			}
			else
			{
				return InExecutionSource->GetExecutionState().GetSelfData();
			}
		}
	}

	return nullptr;
}


void FHCP_VPCGCreatePointsGridElement::GetDependenciesCrc(const FPCGGetDependenciesCrcParams& InParams, FPCGCrc& OutCrc) const
{
	FPCGCrc Crc;
	IPCGElement::GetDependenciesCrc(InParams, Crc);

	if (const UHCP_VPCGCreateHCPGridSettings* Settings = Cast<UHCP_VPCGCreateHCPGridSettings>(InParams.Settings))
	{
		int CoordinateSpace = static_cast<int>(EPCGCoordinateSpace::World);
		bool bCullPointsOutsideVolume = false;
		PCGSettingsHelpers::GetOverrideValue(*InParams.InputData, Settings, GET_MEMBER_NAME_CHECKED(UHCP_VPCGCreateHCPGridSettings, CoordinateSpace), static_cast<int>(Settings->CoordinateSpace), CoordinateSpace);

		// We're using the bounds of the pcg volume, so we extract the actor data here
		EPCGCoordinateSpace EnumCoordinateSpace = static_cast<EPCGCoordinateSpace>(CoordinateSpace);

		if (UPCGData* Data = GetDependenciesData(InParams.ExecutionSource, EnumCoordinateSpace, bCullPointsOutsideVolume))
		{
			Crc.Combine(Data->GetOrComputeCrc(/*bFullDataCrc=*/false));
		}
	}

	OutCrc = Crc;
}

#undef LOCTEXT_NAMESPACE
#undef PCGEX_NAMESPACE