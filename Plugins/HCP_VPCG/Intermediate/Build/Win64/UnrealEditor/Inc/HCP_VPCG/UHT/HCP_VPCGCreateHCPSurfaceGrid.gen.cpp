// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHCP_VPCGCreateHCPSurfaceGrid() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_NoRegister();
HCP_VPCG_API UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot();
HCP_VPCG_API UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition();
PCG_API UClass* Z_Construct_UClass_UPCGSettings();
PCG_API UEnum* Z_Construct_UEnum_PCG_EPCGCoordinateSpace();
UPackage* Z_Construct_UPackage__Script_HCP_VPCG();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHCP_VPCGSurfacePointPosition *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition;
static UEnum* EHCP_VPCGSurfacePointPosition_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition, (UObject*)Z_Construct_UPackage__Script_HCP_VPCG(), TEXT("EHCP_VPCGSurfacePointPosition"));
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.OuterSingleton;
}
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGSurfacePointPosition>()
{
	return EHCP_VPCGSurfacePointPosition_StaticEnum();
}
struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "CellCenter.Name", "EHCP_VPCGSurfacePointPosition::CellCenter" },
		{ "CellCorners.Name", "EHCP_VPCGSurfacePointPosition::CellCorners" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHCP_VPCGSurfacePointPosition::CellCenter", (int64)EHCP_VPCGSurfacePointPosition::CellCenter },
		{ "EHCP_VPCGSurfacePointPosition::CellCorners", (int64)EHCP_VPCGSurfacePointPosition::CellCorners },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HCP_VPCG,
	nullptr,
	"EHCP_VPCGSurfacePointPosition",
	"EHCP_VPCGSurfacePointPosition",
	Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.InnerSingleton, Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfacePointPosition_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition.InnerSingleton;
}
// ********** End Enum EHCP_VPCGSurfacePointPosition ***********************************************

// ********** Begin Enum EHCP_VPCGSurfaceGridPivot *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot;
static UEnum* EHCP_VPCGSurfaceGridPivot_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot, (UObject*)Z_Construct_UPackage__Script_HCP_VPCG(), TEXT("EHCP_VPCGSurfaceGridPivot"));
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.OuterSingleton;
}
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGSurfaceGridPivot>()
{
	return EHCP_VPCGSurfaceGridPivot_StaticEnum();
}
struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Global.Name", "EHCP_VPCGSurfaceGridPivot::Global" },
		{ "LocalComponent.Name", "EHCP_VPCGSurfaceGridPivot::LocalComponent" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "OriginalComponent.Name", "EHCP_VPCGSurfaceGridPivot::OriginalComponent" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHCP_VPCGSurfaceGridPivot::Global", (int64)EHCP_VPCGSurfaceGridPivot::Global },
		{ "EHCP_VPCGSurfaceGridPivot::OriginalComponent", (int64)EHCP_VPCGSurfaceGridPivot::OriginalComponent },
		{ "EHCP_VPCGSurfaceGridPivot::LocalComponent", (int64)EHCP_VPCGSurfaceGridPivot::LocalComponent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HCP_VPCG,
	nullptr,
	"EHCP_VPCGSurfaceGridPivot",
	"EHCP_VPCGSurfaceGridPivot",
	Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.InnerSingleton, Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot.InnerSingleton;
}
// ********** End Enum EHCP_VPCGSurfaceGridPivot ***************************************************

// ********** Begin Class UHCP_VPCGCreateHCPSurfaceGridSettings ************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings;
UClass* UHCP_VPCGCreateHCPSurfaceGridSettings::GetPrivateStaticClass()
{
	using TClass = UHCP_VPCGCreateHCPSurfaceGridSettings;
	if (!Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HCP_VPCGCreateHCPSurfaceGridSettings"),
			Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.InnerSingleton,
			StaticRegisterNativesUHCP_VPCGCreateHCPSurfaceGridSettings,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_NoRegister()
{
	return UHCP_VPCGCreateHCPSurfaceGridSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Procedural" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Creates a 2D or 3D Hexagonal Close Packing (HCP) grid of points.\n */" },
#endif
		{ "IncludePath", "HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a 2D or 3D Hexagonal Close Packing (HCP) grid of points." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridExtents_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//FVector GridExtents = FVector(500.0, 500.0, 500.0);\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FVector GridExtents = FVector(500.0, 500.0, 500.0);" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "PCG_Overridable", "" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointSteepness_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Each PCG point represents a discretized, volumetric region of world space. The points' Steepness value [0.0 to\n\x09 * 1.0] establishes how \"hard\" or \"soft\" that volume will be represented. From 0, it will ramp up linearly\n\x09 * increasing its influence over the density from the point's center to up to two times the bounds. At 1, it will\n\x09 * represent a binary box function with the size of the point's bounds.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Each PCG point represents a discretized, volumetric region of world space. The points' Steepness value [0.0 to\n1.0] establishes how \"hard\" or \"soft\" that volume will be represented. From 0, it will ramp up linearly\nincreasing its influence over the density from the point's center to up to two times the bounds. At 1, it will\nrepresent a binary box function with the size of the point's bounds." },
#endif
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridPivot_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the points transform to world or local space*/" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the points transform to world or local space" },
#endif
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoordinateSpace_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the generation referential of the points *///EPCGCoordinateSpace CoordinateSpace = EPCGCoordinateSpace::World; // Original code \n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "PCG_Overridable", "" },
		{ "PCG_OverrideAliases", "GridPivot" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the generation referential of the points //EPCGCoordinateSpace CoordinateSpace = EPCGCoordinateSpace::World; // Original code" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSetPointsBounds_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, the bounds of the points are set to 50.0, if false, 1.0 */" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPSurfaceGrid.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the bounds of the points are set to 50.0, if false, 1.0" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHCP_VPCGCreateHCPSurfaceGridSettings constinit property declarations ****
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridExtents;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PointSteepness;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_GridPivot_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GridPivot;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CoordinateSpace_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CoordinateSpace;
	static void NewProp_bSetPointsBounds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSetPointsBounds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHCP_VPCGCreateHCPSurfaceGridSettings constinit property declarations ******
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHCP_VPCGCreateHCPSurfaceGridSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics

// ********** Begin Class UHCP_VPCGCreateHCPSurfaceGridSettings Property Definitions ***************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridExtents = { "GridExtents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPSurfaceGridSettings, GridExtents), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridExtents_MetaData), NewProp_GridExtents_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPSurfaceGridSettings, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_PointSteepness = { "PointSteepness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPSurfaceGridSettings, PointSteepness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointSteepness_MetaData), NewProp_PointSteepness_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridPivot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridPivot = { "GridPivot", nullptr, (EPropertyFlags)0x0010000820000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPSurfaceGridSettings, GridPivot_DEPRECATED), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGSurfaceGridPivot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPivot_MetaData), NewProp_GridPivot_MetaData) }; // 2400280757
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CoordinateSpace_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CoordinateSpace = { "CoordinateSpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPSurfaceGridSettings, CoordinateSpace), Z_Construct_UEnum_PCG_EPCGCoordinateSpace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoordinateSpace_MetaData), NewProp_CoordinateSpace_MetaData) }; // 1008406180
void Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_bSetPointsBounds_SetBit(void* Obj)
{
	((UHCP_VPCGCreateHCPSurfaceGridSettings*)Obj)->bSetPointsBounds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_bSetPointsBounds = { "bSetPointsBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGCreateHCPSurfaceGridSettings), &Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_bSetPointsBounds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSetPointsBounds_MetaData), NewProp_bSetPointsBounds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_PointSteepness,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridPivot_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_GridPivot,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CoordinateSpace_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_CoordinateSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::NewProp_bSetPointsBounds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::PropPointers) < 2048);
// ********** End Class UHCP_VPCGCreateHCPSurfaceGridSettings Property Definitions *****************
UObject* (*const Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPCGSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HCP_VPCG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::ClassParams = {
	&UHCP_VPCGCreateHCPSurfaceGridSettings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::Class_MetaDataParams)
};
void UHCP_VPCGCreateHCPSurfaceGridSettings::StaticRegisterNativesUHCP_VPCGCreateHCPSurfaceGridSettings()
{
}
UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings()
{
	if (!Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.OuterSingleton, Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHCP_VPCGCreateHCPSurfaceGridSettings);
UHCP_VPCGCreateHCPSurfaceGridSettings::~UHCP_VPCGCreateHCPSurfaceGridSettings() {}
// ********** End Class UHCP_VPCGCreateHCPSurfaceGridSettings **************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHCP_VPCGSurfacePointPosition_StaticEnum, TEXT("EHCP_VPCGSurfacePointPosition"), &Z_Registration_Info_UEnum_EHCP_VPCGSurfacePointPosition, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2561254445U) },
		{ EHCP_VPCGSurfaceGridPivot_StaticEnum, TEXT("EHCP_VPCGSurfaceGridPivot"), &Z_Registration_Info_UEnum_EHCP_VPCGSurfaceGridPivot, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2400280757U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings, UHCP_VPCGCreateHCPSurfaceGridSettings::StaticClass, TEXT("UHCP_VPCGCreateHCPSurfaceGridSettings"), &Z_Registration_Info_UClass_UHCP_VPCGCreateHCPSurfaceGridSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHCP_VPCGCreateHCPSurfaceGridSettings), 3333214371U) },
	};
}; // Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_179418242{
	TEXT("/Script/HCP_VPCG"),
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPSurfaceGrid_h__Script_HCP_VPCG_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
