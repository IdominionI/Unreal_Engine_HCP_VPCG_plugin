// Fill out your copyright notice in the Description page of Project Settings.

#include "HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h"

#include "PCGContext.h"
#include "PCGCustomVersion.h"
#include "PCGParamData.h"
#include "PCGPin.h"
#include "Data/PCGBasePointData.h"
#include "Data/PCGSpatialData.h"
#include "Helpers/PCGHelpers.h"
#include "Metadata/Accessors/IPCGAttributeAccessorTpl.h"
#include "Metadata/Accessors/PCGAttributeAccessorHelpers.h"
#include "Metadata/Accessors/PCGCustomAccessor.h"

#include "HCP_PCG/Objects/hcp_voxel_storage.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(hcp_vpcg_odd_even_level_filter)

#define LOCTEXT_NAMESPACE "HCP_VPCGOddEvenFilter"

#define INPUT_PIN00_LABEL  TEXT("HCP Grid")
#define OUTPUT_PIN00_LABEL TEXT("Even Levels")
#define OUTPUT_PIN01_LABEL TEXT("Odd Levels")

namespace HCP_VPCGAttributeFilterConstants
{
	constexpr int32 ChunkSize = 256;

#if WITH_EDITOR
	const FText InputPinTooltip = LOCTEXT("InputPinTooltip", "This pin accepts Point data and Attribute Sets. Spatial data will be collapsed to point data.");

	const FText FilterPinTooltip = LOCTEXT("FilterPinTooltip", "This pin accepts Statial data and Attribute Sets. If the data is Spatial, it will automatically sample input points in it. "
		"If it is points, it will sample if \"Spatial Query\" is enabled, otherwise points number need to match with input.");
#endif // WITH_EDITOR

	constexpr int32 DefaultAliasIndex = 0;
	constexpr int32 PointFilterAliasIndex = 1;
	constexpr int32 AttributeFilterAliasIndex = 2;
}


////////////////////////////////////////
// UHCP_VPCGOddEvenLevelFilterSettings
////////////////////////////////////////

FPCGDataTypeIdentifier UHCP_VPCGOddEvenLevelFilterSettings::GetCurrentPinTypesID(const UPCGPin* InPin) const
{
	check(InPin);
	if (!InPin->IsOutputPin())
	{
		return Super::GetCurrentPinTypesID(InPin);
	}

	// Output pin narrows to union of inputs on first pin
	//const FPCGDataTypeIdentifier InputTypeUnion = GetTypeUnionIDOfIncidentEdges(PCGPinConstants::DefaultInputLabel);
	const FPCGDataTypeIdentifier InputTypeUnion = GetTypeUnionIDOfIncidentEdges(INPUT_PIN00_LABEL);

	// Spatial is collapsed into points
	if (InputTypeUnion.IsValid() && (InputTypeUnion & EPCGDataType::Spatial) == InputTypeUnion)
	{
		return FPCGDataTypeIdentifier{ EPCGDataType::Point };
	}
	else
	{
		return InputTypeUnion.IsValid() ? InputTypeUnion : FPCGDataTypeIdentifier{ EPCGDataType::Any };
	}
}

TArray<FPCGPinProperties> UHCP_VPCGOddEvenLevelFilterSettings::InputPinProperties() const
{
	TArray<FPCGPinProperties> PinProperties;
	//FPCGPinProperties& DataToFilterPinProperty = PinProperties.Emplace_GetRef(PCGPinConstants::DefaultInputLabel, EPCGDataType::PointOrParam);
	FPCGPinProperties& DataToFilterPinProperty = PinProperties.Emplace_GetRef(INPUT_PIN00_LABEL, EPCGDataType::PointOrParam);
	DataToFilterPinProperty.SetRequiredPin();

#if WITH_EDITOR
	PinProperties.Last().Tooltip = HCP_VPCGAttributeFilterConstants::InputPinTooltip;
#endif //WITH_EDITOR

	return PinProperties;
}

TArray<FPCGPinProperties> UHCP_VPCGOddEvenLevelFilterSettings::OutputPinProperties() const
{
	//const FName even_level_fname = TEXT("Even level");

	TArray<FPCGPinProperties> PinProperties;
	//PinProperties.Emplace(PCGPinConstants::DefaultInFilterLabel, EPCGDataType::PointOrParam);
	//PinProperties.Emplace(TEXT("Even levels"), EPCGDataType::PointOrParam); // It seems that Unreal pins have their ability to transfer data from one node out pin to another node in pin is dependent upon thier out pin label text !!!!!!
	PinProperties.Emplace(OUTPUT_PIN00_LABEL, EPCGDataType::PointOrParam); // It seems that Unreal pins have their ability to transfer data from one node out pin to another node in pin is dependent upon thier out pin label text !!!!!!
	//PinProperties.Emplace(PCGPinConstants::DefaultOutFilterLabel, EPCGDataType::PointOrParam);
	//PinProperties.Emplace(TEXT("Odd Levels"), EPCGDataType::PointOrParam);
	PinProperties.Emplace(OUTPUT_PIN01_LABEL, EPCGDataType::PointOrParam);

	return PinProperties;
}

FString UHCP_VPCGOddEvenLevelFilterSettings::GetAdditionalTitleInformation() const
{
#if WITH_EDITOR
	if (IsPropertyOverriddenByPin(GET_MEMBER_NAME_CHECKED(UHCP_VPCGOddEvenLevelFilterSettings, TargetAttribute)))
	{
		return FString();
	}
	else
#endif
	{
		return TargetAttribute.GetDisplayText().ToString();
		//return FString("Index");
	}
}

FPCGElementPtr UHCP_VPCGOddEvenLevelFilterSettings::CreateElement() const
{
	return MakeShared<FHCP_VPCGAttributeFilterElement>();
}

UHCP_VPCGOddEvenLevelFilterSettings::UHCP_VPCGOddEvenLevelFilterSettings()
	: UPCGSettings()
{
	// Previous default object was: density for both selectors
	// Recreate the same default
	TargetAttribute.SetPointProperty(EPCGPointProperties::Density);
}

#if WITH_EDITOR
TArray<FPCGPreConfiguredSettingsInfo> UHCP_VPCGOddEvenLevelFilterSettings::GetPreconfiguredInfo() const
{
	TArray<FPCGPreConfiguredSettingsInfo> PreconfiguredInfo;
	PreconfiguredInfo.Emplace(HCP_VPCGAttributeFilterConstants::DefaultAliasIndex, GetDefaultNodeTitle());
	// Only need one odd/even level filter listed in UE PCG node list so comment out other list entry text to this node to avoid duplication and confusion
	//PreconfiguredInfo.Emplace(HCP_VPCGAttributeFilterConstants::PointFilterAliasIndex, LOCTEXT("PointNodeTitle", "Point Filter"));
	//PreconfiguredInfo.Emplace(HCP_VPCGAttributeFilterConstants::PointFilterAliasIndex, LOCTEXT("PointNodeTitle", "HCP odd/even point level Filter"));
	//PreconfiguredInfo.Emplace(HCP_VPCGAttributeFilterConstants::AttributeFilterAliasIndex, LOCTEXT("AttributeNodeTitle", "Attribute Filter"));
	//PreconfiguredInfo.Emplace(HCP_VPCGAttributeFilterConstants::AttributeFilterAliasIndex, LOCTEXT("AttributeNodeTitle", "HCP odd/even level Filter"));

	return PreconfiguredInfo;
}
#endif

void UHCP_VPCGOddEvenLevelFilterSettings::ApplyPreconfiguredSettings(const FPCGPreConfiguredSettingsInfo& PreconfigureInfo)
{
	// If index is 1, it is the default ($Density)
	if (PreconfigureInfo.PreconfiguredIndex != HCP_VPCGAttributeFilterConstants::PointFilterAliasIndex)
	{
		TargetAttribute.SetAttributeName(PCGMetadataAttributeConstants::LastAttributeName);
	}
}

void UHCP_VPCGOddEvenLevelFilterSettings::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	// Check for the data spatial to point gate version
	if (DataVersion < FPCGCustomVersion::NoMoreSpatialDataConversionToPointDataByDefaultOnNonPointPins)
	{
		bHasSpatialToPointDeprecation = true;
	}
#endif // WITH_EDITOR
}



////////////////////////////////////////
// FHCP_VPCGAttributeFilterElementBase
////////////////////////////////////////

bool FHCP_VPCGAttributeFilterElementBase::DoFiltering(FPCGContext* Context, FVector GridExtents, double CellSize, const FPCGAttributePropertyInputSelector& InTargetAttribute, bool bHasSpatialToPointDeprecation, bool bAlwaysGenerateOutputData) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FHCP_VPCGAttributeFilterElementBase::DoFiltering);
	check(Context);

	struct FOperationData
	{
		const UPCGBasePointData* OriginalPointData = nullptr;
		UPCGBasePointData* InFilterPointData = nullptr;
		UPCGBasePointData* OutFilterPointData = nullptr;
		TBitArray<TInlineAllocator<2048>> FilterBitArray;

		const UPCGData* OriginalData = nullptr;
		UPCGMetadata* InFilterMetadata = nullptr;
		UPCGMetadata* OutFilterMetadata = nullptr;

		bool bIsInputPointData = false;
	} OperationData;

	//TArray<FPCGTaggedData> DataToFilter = Context->InputData.GetInputsByPin(PCGPinConstants::DefaultInputLabel);
	TArray<FPCGTaggedData> DataToFilter = Context->InputData.GetInputsByPin(INPUT_PIN00_LABEL);
	TArray<FPCGTaggedData>& Outputs = Context->OutputData.TaggedData;

	//const EHCP_VPCGAttributeFilterOperator Operator = InOperation;

	// If there is no input, do nothing
	if (DataToFilter.IsEmpty())
	{
		return true;
	}

	//BEGIN added code ++++++++++++++++++++++++++++++++++++++++++++++
	// if have incompatible grid extents or cell size issue message and do nothing
	// Until can find number of data grid points imported to this node which PCG does not give, cannot test for this
	// DataToFilter.Num() is the number of input pins or data streams, not the number of data points being inported !!!!
	hcp_voxel_storage voxel_object_data;

	FIntVector3 voxel_volume_dim = voxel_object_data.calc_voxel_volume_dimensions(GridExtents, CellSize);

	//END added code ++++++++++++++++++++++++++++++++++++++++++++++


	for (const FPCGTaggedData& Input : DataToFilter)
	{
		const UPCGData* OriginalData = Input.Data;
		if (!OriginalData)
		{
			continue;
		}

		if (const UPCGSpatialData* SpatialInput = Cast<const UPCGSpatialData>(OriginalData))
		{
			if (!SpatialInput->IsA<UPCGBasePointData>())
			{
				const UPCGBasePointData* OriginalPointData = nullptr;

				if (bHasSpatialToPointDeprecation)
				{
					OriginalPointData = SpatialInput->ToBasePointData(Context);
				}

				if (!OriginalPointData)
				{
					PCGE_LOG(Error, GraphAndLog, LOCTEXT("NoPointDataInInput", "Unable to get point data from input. Use a conversion node before this node to transform it to points."));
					continue;
				}

				OperationData.bIsInputPointData = true;
				OriginalData = OriginalPointData;
			}
			else
			{
				OperationData.bIsInputPointData = true;
				OriginalData = SpatialInput;
			}
		}
		else if (OriginalData->IsA<UPCGParamData>())
		{
			// Disable Spatial Queries
			OperationData.bIsInputPointData = false;
		}
		else
		{
			PCGE_LOG(Error, GraphAndLog, LOCTEXT("InvalidInput", "Input is not a point data nor an attribute set. Unsupported."));
			continue;
		}

		// Helper lambdas to fail nicely and forward input to in/out filter pin
		// If there is a problem with threshold -> forward to InFilter
		auto ForwardInputToInFilterPin = [&Outputs, Input, OriginalData]()
			{
				FPCGTaggedData& InFilterOutput = Outputs.Add_GetRef(Input);
				//InFilterOutput.Pin = PCGPinConstants::DefaultInFilterLabel;
				//InFilterOutput.Pin = TEXT("Even levels");
				InFilterOutput.Pin = OUTPUT_PIN00_LABEL;
				// Use original data because it could have been collapsed
				InFilterOutput.Data = OriginalData;
			};

		// If there is a problem with target -> forward to OutFilter
		auto ForwardInputToOutFilterPin = [&Outputs, Input, OriginalData]()
			{
				FPCGTaggedData& OutFilterOutput = Outputs.Add_GetRef(Input);
				//OutFilterOutput.Pin = PCGPinConstants::DefaultOutFilterLabel;
				//OutFilterOutput.Pin = TEXT("Odd Levels");
				OutFilterOutput.Pin = OUTPUT_PIN01_LABEL;
				// Use original data because it could have been collapsed
				OutFilterOutput.Data = OriginalData;
			};

		FPCGAttributePropertyInputSelector TargetAttribute = InTargetAttribute.CopyAndFixLast(OriginalData);
		TUniquePtr<const IPCGAttributeAccessor> TargetAccessor = PCGAttributeAccessorHelpers::CreateConstAccessor(OriginalData, TargetAttribute);// Is his needed ???
		TUniquePtr<const IPCGAttributeAccessorKeys> TargetKeys = PCGAttributeAccessorHelpers::CreateConstKeys(OriginalData, TargetAttribute);

		if (!TargetAccessor.IsValid() || !TargetKeys.IsValid())
		{
			//if (bWarnOnDataMissingAttribute)
			//{
				PCGE_LOG(Warning, GraphAndLog, FText::Format(LOCTEXT("TargetMissingAttribute", "Input data doesn't have target attribute/property '{0}'"), FText::FromName(TargetAttribute.GetName())));
			//}

			ForwardInputToOutFilterPin();
			continue;
		}

		const int16 TargetType = TargetAccessor->GetUnderlyingType();

		const int32 NumInput = TargetKeys->GetNum();

		if (NumInput == 0)
		{
			ForwardInputToInFilterPin();
			continue;
		}

		OperationData.OriginalData = OriginalData;

		if (OperationData.bIsInputPointData)
		{
			const UPCGBasePointData* OriginalPointData = CastChecked<UPCGBasePointData>(OriginalData);

			OperationData.OriginalPointData = OriginalPointData;

			// Will be set individually in batches
			OperationData.FilterBitArray.SetNumUninitialized(OriginalPointData->GetNumPoints());
		}
		else
		{
			// Param data
			const UPCGParamData* OriginalParamData = CastChecked<UPCGParamData>(OriginalData);

			// Will be set individually in batches
			OperationData.FilterBitArray.SetNumUninitialized(OriginalParamData->Metadata ? OriginalParamData->Metadata->GetItemCountForChild() : 0);
		}

		auto Operation = [&TargetAccessor, &TargetKeys, &OperationData, &GridExtents, &CellSize, &voxel_volume_dim](auto Dummy) -> bool
			{
				using Type = decltype(Dummy);

				const int32 NumberOfEntries = TargetKeys->GetNum();

				if (NumberOfEntries <= 0)
				{
					return false;
				}

				TArray<Type, TFixedAllocator<HCP_VPCGAttributeFilterConstants::ChunkSize>> TargetValues;

				TargetValues.SetNum(HCP_VPCGAttributeFilterConstants::ChunkSize);

				const int32 NumberOfIterations = (NumberOfEntries + HCP_VPCGAttributeFilterConstants::ChunkSize - 1) / HCP_VPCGAttributeFilterConstants::ChunkSize;

				for (int32 i = 0; i < NumberOfIterations; ++i)
				{
					const int32 StartIndex = i * HCP_VPCGAttributeFilterConstants::ChunkSize;
					const int32 Range = FMath::Min(NumberOfEntries - StartIndex, HCP_VPCGAttributeFilterConstants::ChunkSize);
					TArrayView<Type> TargetView(TargetValues.GetData(), Range);
	
					if (!TargetAccessor->GetRange(TargetView, StartIndex, *TargetKeys)){
						return false;
					}

					check(Range == 0 || OperationData.FilterBitArray.IsValidIndex(StartIndex + Range - 1));

					//BEGIN added code ++++++++++++++++++++++++++++++++++++++++++++++
					hcp_voxel_storage voxel_object_data;
					//END added code ++++++++++++++++++++++++++++++++++++++++++++++
					for (int32 j = 0; j < Range; ++j)
					{
						OperationData.FilterBitArray[StartIndex + j] = true;
						bool bShouldKeep = false;

						//BEGIN added code ++++++++++++++++++++++++++++++++++++++++++++++
						FIntVector3 hcp_Voxel_Coord = voxel_object_data.get_matrix_coordinate(StartIndex + j, voxel_volume_dim);
						if (hcp_Voxel_Coord.Z % 2 == 0) bShouldKeep = true;
						//END added code ++++++++++++++++++++++++++++++++++++++++++++++

						OperationData.FilterBitArray[StartIndex + j] = bShouldKeep;
					}
				}

				return true;
			};

		if (PCGMetadataAttribute::CallbackWithRightType(TargetAccessor->GetUnderlyingType(), Operation))
		{
			UPCGData* InFilterData = nullptr;
			UPCGData* OutFilterData = nullptr;

			if (OperationData.bIsInputPointData)
			{
				const int32 NumInFilterPoints = OperationData.FilterBitArray.CountSetBits();
				const int32 NumOutFilterPoints = OperationData.OriginalPointData->GetNumPoints() - NumInFilterPoints;

				FPCGInitializeFromDataParams InitializeFromDataParams(OperationData.OriginalPointData);
				InitializeFromDataParams.bInheritSpatialData = false;
				const FConstPCGPointValueRanges OriginalRanges(OperationData.OriginalPointData);

				// Note: Splitting the set vs unset values is cleaner and likely more optimal, due to branch prediction.

				if (NumInFilterPoints > 0 || bAlwaysGenerateOutputData)
				{
					UPCGBasePointData* InFilterPointData = FPCGContext::NewPointData_AnyThread(Context);
					InFilterPointData->InitializeFromDataWithParams(InitializeFromDataParams);
					InFilterData = InFilterPointData;

					InFilterPointData->SetNumPoints(NumInFilterPoints);
					InFilterPointData->AllocateProperties(OperationData.OriginalPointData->GetAllocatedProperties());
					InFilterPointData->CopyUnallocatedPropertiesFrom(OperationData.OriginalPointData);

					FPCGPointValueRanges InFilterRanges(InFilterPointData, /*bAllocate=*/false);

					int32 InFilterWriteIndex = 0;
					for (TConstSetBitIterator It(OperationData.FilterBitArray); It; ++It)
					{
						InFilterRanges.SetFromValueRanges(InFilterWriteIndex++, OriginalRanges, It.GetIndex());
					}
				}

				if (NumOutFilterPoints > 0 || bAlwaysGenerateOutputData)
				{
					UPCGBasePointData* OutFilterPointData = FPCGContext::NewPointData_AnyThread(Context);
					OutFilterPointData->InitializeFromDataWithParams(InitializeFromDataParams);
					OutFilterData = OutFilterPointData;

					OutFilterPointData->SetNumPoints(NumOutFilterPoints);
					OutFilterPointData->AllocateProperties(OperationData.OriginalPointData->GetAllocatedProperties());
					OutFilterPointData->CopyUnallocatedPropertiesFrom(OperationData.OriginalPointData);

					FPCGPointValueRanges OutFilterRanges(OutFilterPointData, /*bAllocate=*/false);

					// @todo_pcg: Could write a TConstUnsetBitIterator in BitArray.h.
					int32 OutFilterWriteIndex = 0;
					for (int32 Index = 0; Index < OperationData.FilterBitArray.Num(); ++Index)
					{
						if (!OperationData.FilterBitArray[Index])
						{
							OutFilterRanges.SetFromValueRanges(OutFilterWriteIndex++, OriginalRanges, Index);
						}
					}
				}
			}
			else
			{
				check(OperationData.OriginalData);

				if (!OperationData.FilterBitArray.IsEmpty())
				{
					const UPCGMetadata* OriginalMetadata = OperationData.OriginalData->ConstMetadata();
					check(OperationData.FilterBitArray.Num() == OriginalMetadata->GetItemCountForChild())

						TArray<PCGMetadataEntryKey, TInlineAllocator<256>> InEntryKeys;
					TArray<PCGMetadataEntryKey, TInlineAllocator<256>> OutEntryKeys;

					const int32 NumInFilterMetadata = OperationData.FilterBitArray.CountSetBits();
					const int32 NumOutFilterMetadata = OriginalMetadata->GetItemCountForChild() - NumInFilterMetadata;

					InEntryKeys.Reserve(NumInFilterMetadata);
					OutEntryKeys.Reserve(NumOutFilterMetadata);

					for (int32 Index = 0; Index < OperationData.FilterBitArray.Num(); ++Index)
					{
						if (OperationData.FilterBitArray[Index])
						{
							InEntryKeys.Add(Index);
						}
						else
						{
							OutEntryKeys.Add(Index);
						}
					}

					// Add all attributes from the original param data, but without any entry/value. It will be added later.
					if (NumInFilterMetadata > 0 || bAlwaysGenerateOutputData)
					{
						UPCGParamData* InFilterParamData = FPCGContext::NewObject_AnyThread<UPCGParamData>(Context);
						UPCGMetadata* InFilterMetadata = InFilterParamData->Metadata;
						PCGMetadataHelpers::InitializeMetadataWithDataDomainCopyAndElementsNoCopy(OperationData.OriginalData, InFilterParamData);
						InFilterMetadata->AddAttributesFiltered(OriginalMetadata, TSet<FName>(), EPCGMetadataFilterMode::ExcludeAttributes);
						InFilterMetadata->SetAttributes(InEntryKeys, OriginalMetadata, /*InOutOptionalKeys=*/nullptr, Context);
						InFilterData = InFilterParamData;
					}

					if (NumOutFilterMetadata > 0 || bAlwaysGenerateOutputData)
					{
						UPCGParamData* OutFilterParamData = FPCGContext::NewObject_AnyThread<UPCGParamData>(Context);
						UPCGMetadata* OutFilterMetadata = OutFilterParamData->Metadata;
						PCGMetadataHelpers::InitializeMetadataWithDataDomainCopyAndElementsNoCopy(OperationData.OriginalData, OutFilterParamData);
						OutFilterMetadata->AddAttributesFiltered(OriginalMetadata, TSet<FName>(), EPCGMetadataFilterMode::ExcludeAttributes);
						OutFilterMetadata->SetAttributes(OutEntryKeys, OriginalMetadata, /*InOutOptionalKeys=*/nullptr, Context);
						OutFilterData = OutFilterParamData;
					}
				}
			}

			if (InFilterData)
			{
				FPCGTaggedData& InFilterOutput = Outputs.Add_GetRef(Input);
				//InFilterOutput.Pin = PCGPinConstants::DefaultInFilterLabel;
				//InFilterOutput.Pin = TEXT("Even levels");
				InFilterOutput.Pin = OUTPUT_PIN00_LABEL;
				InFilterOutput.Data = InFilterData;
				InFilterOutput.Tags = Input.Tags;
			}

			if (OutFilterData)
			{
				FPCGTaggedData& OutFilterOutput = Outputs.Add_GetRef(Input);
				//OutFilterOutput.Pin = PCGPinConstants::DefaultOutFilterLabel;
				//OutFilterOutput.Pin = TEXT("Odd levels");
				OutFilterOutput.Pin = OUTPUT_PIN01_LABEL;
				OutFilterOutput.Data = OutFilterData;
				OutFilterOutput.Tags = Input.Tags;
			}
		}
		else
		{
			// Should be caught before when computing threshold info.
			PCGE_LOG(Warning, GraphAndLog, LOCTEXT("TypeCannotBeConverted", "Cannot convert threshold type to target type"));
			ForwardInputToInFilterPin();
		}
	}

	return true;
}

////////////////////////////////////////
// FHCP_VPCGAttributeFilterElement
////////////////////////////////////////

bool FHCP_VPCGAttributeFilterElement::ExecuteInternal(FPCGContext* Context) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FHCP_VPCGAttributeFilterElement::Execute);

#if !WITH_EDITOR
	//const bool bHasInFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(PCGPinConstants::DefaultInFilterLabel);
	//const bool bHasInFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(TEXT("Even levels"));
	const bool bHasInFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(OUTPUT_PIN00_LABEL);
	//const bool bHasOutsideFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(PCGPinConstants::DefaultOutFilterLabel);
	//const bool bHasOutsideFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(TEXT("Odd levels"));
	const bool bHasOutsideFilterOutputPin = Context->Node && Context->Node->IsOutputPinConnected(OUTPUT_PIN01_LABEL);

	// Early out - only in non-editor builds, otherwise we will potentially poison the cache, since it is input-driven
	if (!bHasInFilterOutputPin && !bHasOutsideFilterOutputPin)
	{
		return true;
	}
#endif

	const UHCP_VPCGOddEvenLevelFilterSettings* Settings = Context->GetInputSettings<UHCP_VPCGOddEvenLevelFilterSettings>();
	check(Settings);

	return DoFiltering(Context, Settings->GridExtents, Settings->CellSize, Settings->TargetAttribute, Settings->bHasSpatialToPointDeprecation, Settings->bGenerateOutputDataEvenIfEmpty);
}

#undef LOCTEXT_NAMESPACE
