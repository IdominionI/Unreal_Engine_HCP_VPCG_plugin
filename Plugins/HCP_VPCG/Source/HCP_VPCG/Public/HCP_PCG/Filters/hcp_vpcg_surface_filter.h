// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "PCGSettings.h"

#include "HCP_PCG/Automata/hcp_vpcg_dt_voxel_automata.h"
#include "HCP_PCG/Automata/hcp_vpcg_voxel_automata_functions.h"

//#include "PCGDensityFilter.generated.h"
#include "hcp_vpcg_surface_filter.generated.h"

// ***************** Begin 
// These structures need to be moved to another .h files
/*
	voxel_surface_data_class

	C++ class and structures that create a list of verticies as a std::vector class that represents
	the surface of a generated hcp voxel point cloud.
*/

//struct surface_vertices_struct_type {
//	index_data_type voxel_index;
//	index_data_type vertex_id;
//};
//
//struct surface_faces_struct_type {
//	index_data_type face_id;
//	FIntVector3    voxel_index;
//};
//
//struct surface_vertices_normal_struct_type {
//	index_data_type voxel_index;
//	FIntVector3       voxel_normal;
//};
//
//struct surface_faces_normal_struct_type {
//	index_data_type voxel_index;
//	FIntVector3       voxel_normal;
//};

//#define NUMBER_HCP_NEIGHBOURS 12

// ***************** End 

class  hcp_surface_functions_class {
public:
	// Determine if the hcp voxel of the voxel data matrix index coordinate voxel_coordinate is a surface voxel or not
	// A surface voxel is a voxel that has at least one neighbour that has an invalid voxel value.
	bool is_voxel_surface_vertex(FIntVector3 voxel_coordinate, FIntVector3 matrix_dimension, FConstPCGPointValueRanges &ReadRanges);


};


UCLASS(MinimalAPI, BlueprintType, ClassGroup = (Procedural))
class UHCP_VPCGSurface_Filter : public UPCGSettings
{
	GENERATED_BODY()

public:
	//~Begin UPCGSettings interface
#if WITH_EDITOR
	virtual FName GetDefaultNodeName() const override { return FName(TEXT("HCP Surface Filter")); }
	virtual FText GetDefaultNodeTitle() const override { return NSLOCTEXT("HCPVPCGSurfaceFilterSettings", "NodeTitle", "HCP Grid Surface Filter"); }
	virtual EPCGSettingsType GetType() const override { return EPCGSettingsType::Filter; }
#endif

protected:
	virtual TArray<FPCGPinProperties> InputPinProperties() const override { return Super::DefaultPointInputPinProperties(); }
	virtual TArray<FPCGPinProperties> OutputPinProperties() const override { return Super::DefaultPointOutputPinProperties(); }
	virtual FPCGElementPtr CreateElement() const override;
	//~End UPCGSettings interface

public:
	// BEGIN Added Code +++++++++++++++++++++++++++++++
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	FVector GridExtents = FVector(500.0, 500.0, 500.0);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable, ClampMin = "0.0", UIMin = "0.0"))
	//FVector CellSize = FVector(100.0, 100.0, 100.0);
	double CellSize = 50.0;

	// END Added Code+++++++++++++++++++++++++++++++

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (ClampMin = "0", ClampMax = "1", PCG_Overridable))
	float LowerBound = 0.5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (ClampMin = "0", ClampMax = "1", PCG_Overridable))
	float UpperBound = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable))
	bool bInvertFilter = false;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, BlueprintReadWrite, EditAnywhere, Category = "Settings|Debug", meta = (PCG_Overridable))
	bool bKeepZeroDensityPoints = false;
#endif
};

class FHCP_VPCGSurfaceFilterElement : public IPCGElement
{
protected:
	virtual bool ExecuteInternal(FPCGContext* Context) const override;
	virtual EPCGElementExecutionLoopMode ExecutionLoopMode(const UPCGSettings* Settings) const override { return EPCGElementExecutionLoopMode::SinglePrimaryPin; }
	virtual bool SupportsBasePointDataInputs(FPCGContext* InContext) const override { return true; }
};
