// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h"

#ifdef HCP_VPCG_HCP_VPCGCreateHCPMatrixGrid_generated_h
#error "HCP_VPCGCreateHCPMatrixGrid.generated.h already included, missing '#pragma once' in HCP_VPCGCreateHCPMatrixGrid.h"
#endif
#define HCP_VPCG_HCP_VPCGCreateHCPMatrixGrid_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UHCP_VPCGCreateHCPGridSettings *******************************************
struct Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics;
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_NoRegister();

#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHCP_VPCGCreateHCPGridSettings(); \
	friend struct ::Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend HCP_VPCG_API UClass* ::Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UHCP_VPCGCreateHCPGridSettings, UPCGSettings, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HCP_VPCG"), Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_NoRegister) \
	DECLARE_SERIALIZER(UHCP_VPCGCreateHCPGridSettings)


#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_33_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHCP_VPCGCreateHCPGridSettings(UHCP_VPCGCreateHCPGridSettings&&) = delete; \
	UHCP_VPCGCreateHCPGridSettings(const UHCP_VPCGCreateHCPGridSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHCP_VPCGCreateHCPGridSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHCP_VPCGCreateHCPGridSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHCP_VPCGCreateHCPGridSettings) \
	NO_API virtual ~UHCP_VPCGCreateHCPGridSettings();


#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_30_PROLOG
#define FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_33_INCLASS_NO_PURE_DECLS \
	FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHCP_VPCGCreateHCPGridSettings;

// ********** End Class UHCP_VPCGCreateHCPGridSettings *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h

// ********** Begin Enum EHCP_VPCGPointPosition ****************************************************
#define FOREACH_ENUM_EHCP_VPCGPOINTPOSITION(op) \
	op(EHCP_VPCGPointPosition::CellCenter) \
	op(EHCP_VPCGPointPosition::CellCorners) 

enum class EHCP_VPCGPointPosition : uint8;
template<> struct TIsUEnumClass<EHCP_VPCGPointPosition> { enum { Value = true }; };
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGPointPosition>();
// ********** End Enum EHCP_VPCGPointPosition ******************************************************

// ********** Begin Enum EHCP_VPCGGridPivot ********************************************************
#define FOREACH_ENUM_EHCP_VPCGGRIDPIVOT(op) \
	op(EHCP_VPCGGridPivot::Global) \
	op(EHCP_VPCGGridPivot::OriginalComponent) \
	op(EHCP_VPCGGridPivot::LocalComponent) 

enum class EHCP_VPCGGridPivot : uint8;
template<> struct TIsUEnumClass<EHCP_VPCGGridPivot> { enum { Value = true }; };
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGGridPivot>();
// ********** End Enum EHCP_VPCGGridPivot **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
