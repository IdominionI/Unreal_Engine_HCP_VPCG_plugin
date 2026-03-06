// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "PCGSettings.h"
#include "Metadata/PCGAttributePropertySelector.h"
#include "Metadata/PCGMetadataTypesConstantStruct.h"

#include "hcp_vpcg_odd_even_level_filter.generated.h"

UCLASS(MinimalAPI, BlueprintType, ClassGroup = (Procedural))
class UHCP_VPCGOddEvenLevelFilterSettings : public UPCGSettings
{
	GENERATED_BODY()

public:
	UHCP_VPCGOddEvenLevelFilterSettings();

	//~Begin UObject interface
	virtual void PostLoad() override;
	//~End UObject interface

	//~Begin UPCGSettings interface
#if WITH_EDITOR
	virtual FName GetDefaultNodeName() const override { return FName(TEXT("HCP_VPCGOddEvenFilter")); }
	virtual FText GetDefaultNodeTitle() const override { return NSLOCTEXT("HCP_VPCGAttributeFilteringElement", "NodeTitle", "HCP Filter Odd Even Levels"); }
	virtual EPCGSettingsType GetType() const override { return EPCGSettingsType::Filter; }

	// Expose 2 nodes: Attribute filter and Point Filter that will not have the same defaults.
	virtual TArray<FPCGPreConfiguredSettingsInfo> GetPreconfiguredInfo() const override;
	virtual bool OnlyExposePreconfiguredSettings() const override { return true; }
	virtual bool GroupPreconfiguredSettings() const override { return false; }
#endif
	virtual void ApplyPreconfiguredSettings(const FPCGPreConfiguredSettingsInfo& PreconfigureInfo) override;
	virtual FString GetAdditionalTitleInformation() const override;
	virtual bool HasDynamicPins() const override { return true; }
	virtual FPCGDataTypeIdentifier GetCurrentPinTypesID(const UPCGPin* InPin) const override;

protected:
	virtual TArray<FPCGPinProperties> InputPinProperties() const override;
	virtual TArray<FPCGPinProperties> OutputPinProperties() const override;
	virtual FPCGElementPtr CreateElement() const override;
	//~End UPCGSettings interface

public:
	// BEGIN Added Code+++++++++++++++++++++++++++++++
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	FVector GridExtents = FVector(500.0, 500.0, 500.0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	//FVector CellSize = FVector(100.0, 100.0, 100.0);
	double CellSize = 50.0;

	// END Added Code+++++++++++++++++++++++++++++++

	/** Target property/attribute related properties */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable)) // original code no need to have as a input pin
	UPROPERTY()
	FPCGAttributePropertyInputSelector TargetAttribute;// This needs to be set to $Index

	/** Always generate output data (possibly empty) for both the in and out filters, even if all/none of the elements were filtered. */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings)// original code no need to have as a input pin
	UPROPERTY()
	bool bGenerateOutputDataEvenIfEmpty = true;

	// Hidden value to indicate that Spatial -> Point deprecation is on where pins are not explicitly points.
	UPROPERTY()
	bool bHasSpatialToPointDeprecation = false;
};

class FHCP_VPCGAttributeFilterElementBase : public IPCGElement
{
protected:
	virtual EPCGElementExecutionLoopMode ExecutionLoopMode(const UPCGSettings* Settings) const override { return EPCGElementExecutionLoopMode::SinglePrimaryPin; }
	virtual bool SupportsBasePointDataInputs(FPCGContext* InContext) const override { return true; }

	/** Performs the filter operation. Returns true when the operation is complete. */
	bool DoFiltering(FPCGContext* Context, FVector GridExtents, double CellSize, const FPCGAttributePropertyInputSelector& InTargetAttribute, bool bHasSpatialToPointDeprecation, bool bAlwaysGenerateOutputData) const;
};

class FHCP_VPCGAttributeFilterElement : public FHCP_VPCGAttributeFilterElementBase
{
protected:
	virtual bool ExecuteInternal(FPCGContext* Context) const override;
};



