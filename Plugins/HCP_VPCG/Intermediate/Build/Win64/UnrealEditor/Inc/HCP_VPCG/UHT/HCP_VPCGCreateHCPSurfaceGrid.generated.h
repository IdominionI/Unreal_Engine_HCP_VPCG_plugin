// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h"

#ifdef HCP_VPCG_HCP_VPCGCreateHCPSurfaceGrid_generated_h
#error "HCP_VPCGCreateHCPSurfaceGrid.generated.h already included, missing '#pragma once' in HCP_VPCGCreateHCPSurfaceGrid.h"
#endif
#define HCP_VPCG_HCP_VPCGCreateHCPSurfaceGrid_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UHCP_VPCGCreateHCPSurfaceGridSettings ************************************
struct Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics;
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_NoRegister();

#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHCP_VPCGCreateHCPSurfaceGridSettings(); \
	friend struct ::Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HCP_VPCG_API UClass* ::Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UHCP_VPCGCreateHCPSurfaceGridSettings, UPCGSettings, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HCP_VPCG"), Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_NoRegister) \
	DECLARE_SERIALIZER(UHCP_VPCGCreateHCPSurfaceGridSettings)


#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_33_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHCP_VPCGCreateHCPSurfaceGridSettings(UHCP_VPCGCreateHCPSurfaceGridSettings&&) = delete; \
	UHCP_VPCGCreateHCPSurfaceGridSettings(const UHCP_VPCGCreateHCPSurfaceGridSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHCP_VPCGCreateHCPSurfaceGridSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHCP_VPCGCreateHCPSurfaceGridSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHCP_VPCGCreateHCPSurfaceGridSettings) \
	NO_API virtual ~UHCP_VPCGCreateHCPSurfaceGridSettings();


#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_30_PROLOG
#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_33_INCLASS_NO_PURE_DECLS \
	FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHCP_VPCGCreateHCPSurfaceGridSettings;

// ********** End Class UHCP_VPCGCreateHCPSurfaceGridSettings **************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h

// ********** Begin Enum EHCP_VPCGSurfacePointPosition *********************************************
#define FOREACH_ENUM_EHCP_VPCGSURFACEPOINTPOSITION(op) \
	op(EHCP_VPCGSurfacePointPosition::CellCenter) \
	op(EHCP_VPCGSurfacePointPosition::CellCorners) 

enum class EHCP_VPCGSurfacePointPosition : uint8;
template<> struct TIsUEnumClass<EHCP_VPCGSurfacePointPosition> { enum { Value = true }; };
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGSurfacePointPosition>();
// ********** End Enum EHCP_VPCGSurfacePointPosition ***********************************************

// ********** Begin Enum EHCP_VPCGSurfaceGridPivot *************************************************
#define FOREACH_ENUM_EHCP_VPCGSURFACEGRIDPIVOT(op) \
	op(EHCP_VPCGSurfaceGridPivot::Global) \
	op(EHCP_VPCGSurfaceGridPivot::OriginalComponent) \
	op(EHCP_VPCGSurfaceGridPivot::LocalComponent) 

enum class EHCP_VPCGSurfaceGridPivot : uint8;
template<> struct TIsUEnumClass<EHCP_VPCGSurfaceGridPivot> { enum { Value = true }; };
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGSurfaceGridPivot>();
// ********** End Enum EHCP_VPCGSurfaceGridPivot ***************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
