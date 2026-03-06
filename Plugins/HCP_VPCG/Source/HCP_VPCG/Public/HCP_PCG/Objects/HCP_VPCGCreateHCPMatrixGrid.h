// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "PCGSettings.h"

#include "Data/PCGPointData.h"
//#include "hcp_voxel.generated.h"
#include "HCP_VPCGCreateHCPMatrixGrid.generated.h"

UENUM()
enum class EHCP_VPCGPointPosition : uint8
{
	CellCenter,
	CellCorners
};

UENUM()
enum class UE_DEPRECATED(5.4, "Not used anymore, replaced by EHCP_VPCGCoordinateSpace.") EHCP_VPCGGridPivot : uint8
{
	Global,
		OriginalComponent,
		LocalComponent
};

/**
 * Creates a 2D or 3D Hexagonal Close Packing (HCP) grid of points.
 */
UCLASS(BlueprintType, ClassGroup = (Procedural))
class UHCP_VPCGCreateHCPGridSettings : public UPCGSettings
{
	GENERATED_BODY()

public:
	UHCP_VPCGCreateHCPGridSettings();

	//~Begin UObject interface
	virtual void PostLoad() override;
	//~End UObject interface

	//~Begin UHCP_VPCGSettings interface
#if WITH_EDITOR
	virtual FName GetDefaultNodeName() const override { return FName(TEXT("CreateHcpVoxelPointsGrid")); }
	virtual FText GetDefaultNodeTitle() const override { return NSLOCTEXT("HCP_VPCGCreatePointsGridElement", "NodeTitle", "Create HCP voxel Points Grid"); }
	virtual FText GetNodeTooltipText() const override { return NSLOCTEXT("HCP_VPCGCreatePointsGridElement", "NodeTooltip", "Creates a 2D or 3D hexagonal close packing grid of points."); }
	virtual EPCGSettingsType GetType() const override { return EPCGSettingsType::Spatial; }
#endif

protected:
	virtual TArray<FPCGPinProperties> InputPinProperties() const override;
	virtual TArray<FPCGPinProperties> OutputPinProperties() const override { return Super::DefaultPointOutputPinProperties(); }
	virtual FPCGElementPtr CreateElement() const override;
	//~End UHCP_VPCGSettings interface

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	FVector GridExtents = FVector(500.0, 500.0, 500.0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	double CellSize = 50.0;

	/** Each PCG point represents a discretized, volumetric region of world space. The points' Steepness value [0.0 to
	 * 1.0] establishes how "hard" or "soft" that volume will be represented. From 0, it will ramp up linearly
	 * increasing its influence over the density from the point's center to up to two times the bounds. At 1, it will
	 * represent a binary box function with the size of the point's bounds.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (ClampMin = "0", ClampMax = "1", PCG_Overridable))
	float PointSteepness = 0.5f;

#if WITH_EDITORONLY_DATA
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
		/** Sets the points transform to world or local space*/
		UPROPERTY()
	EHCP_VPCGGridPivot GridPivot_DEPRECATED = EHCP_VPCGGridPivot::Global;
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
#endif

	/** Sets the generation referential of the points */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, PCG_OverrideAliases = "GridPivot"))
	//EPCGCoordinateSpace CoordinateSpace = EPCGCoordinateSpace::World; // Original code 
	EPCGCoordinateSpace CoordinateSpace = EPCGCoordinateSpace::LocalComponent;

	/** If true, the bounds of the points are set to 50.0, if false, 1.0 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable))
	bool bSetPointsBounds = true;

	// Original code that has been excluded as no points should be removed from a HCP grid 
	/** If true, points are removed if they are outside of the volume */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable))
	//bool bCullPointsOutsideVolume = false;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable))
	//EHCP_VPCGPointPosition PointPosition = EHCP_VPCGPointPosition::CellCenter;
};

class FHCP_VPCGCreatePointsGridElement : public IPCGElement
{
public:
	virtual void GetDependenciesCrc(const FPCGGetDependenciesCrcParams& InParams, FPCGCrc& OutCrc) const override;
	virtual bool SupportsBasePointDataInputs(FPCGContext* InContext) const override { return true; }

protected:
	virtual bool ExecuteInternal(FPCGContext* Context) const override;
};