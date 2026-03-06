// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHCP_VPCGCreateHCPMatrixGrid() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_NoRegister();
HCP_VPCG_API UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot();
HCP_VPCG_API UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition();
PCG_API UClass* Z_Construct_UClass_UPCGSettings();
PCG_API UEnum* Z_Construct_UEnum_PCG_EPCGCoordinateSpace();
UPackage* Z_Construct_UPackage__Script_HCP_VPCG();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EHCP_VPCGPointPosition ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHCP_VPCGPointPosition;
static UEnum* EHCP_VPCGPointPosition_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition, (UObject*)Z_Construct_UPackage__Script_HCP_VPCG(), TEXT("EHCP_VPCGPointPosition"));
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.OuterSingleton;
}
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGPointPosition>()
{
	return EHCP_VPCGPointPosition_StaticEnum();
}
struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "CellCenter.Name", "EHCP_VPCGPointPosition::CellCenter" },
		{ "CellCorners.Name", "EHCP_VPCGPointPosition::CellCorners" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHCP_VPCGPointPosition::CellCenter", (int64)EHCP_VPCGPointPosition::CellCenter },
		{ "EHCP_VPCGPointPosition::CellCorners", (int64)EHCP_VPCGPointPosition::CellCorners },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HCP_VPCG,
	nullptr,
	"EHCP_VPCGPointPosition",
	"EHCP_VPCGPointPosition",
	Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.InnerSingleton, Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGPointPosition_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGPointPosition.InnerSingleton;
}
// ********** End Enum EHCP_VPCGPointPosition ******************************************************

// ********** Begin Enum EHCP_VPCGGridPivot ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHCP_VPCGGridPivot;
static UEnum* EHCP_VPCGGridPivot_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot, (UObject*)Z_Construct_UPackage__Script_HCP_VPCG(), TEXT("EHCP_VPCGGridPivot"));
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.OuterSingleton;
}
template<> HCP_VPCG_NON_ATTRIBUTED_API UEnum* StaticEnum<EHCP_VPCGGridPivot>()
{
	return EHCP_VPCGGridPivot_StaticEnum();
}
struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Global.Name", "EHCP_VPCGGridPivot::Global" },
		{ "LocalComponent.Name", "EHCP_VPCGGridPivot::LocalComponent" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
		{ "OriginalComponent.Name", "EHCP_VPCGGridPivot::OriginalComponent" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EHCP_VPCGGridPivot::Global", (int64)EHCP_VPCGGridPivot::Global },
		{ "EHCP_VPCGGridPivot::OriginalComponent", (int64)EHCP_VPCGGridPivot::OriginalComponent },
		{ "EHCP_VPCGGridPivot::LocalComponent", (int64)EHCP_VPCGGridPivot::LocalComponent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_HCP_VPCG,
	nullptr,
	"EHCP_VPCGGridPivot",
	"EHCP_VPCGGridPivot",
	Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot()
{
	if (!Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.InnerSingleton, Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EHCP_VPCGGridPivot.InnerSingleton;
}
// ********** End Enum EHCP_VPCGGridPivot **********************************************************

// ********** Begin Class UHCP_VPCGCreateHCPGridSettings *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings;
UClass* UHCP_VPCGCreateHCPGridSettings::GetPrivateStaticClass()
{
	using TClass = UHCP_VPCGCreateHCPGridSettings;
	if (!Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HCP_VPCGCreateHCPGridSettings"),
			Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.InnerSingleton,
			StaticRegisterNativesUHCP_VPCGCreateHCPGridSettings,
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
	return Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_NoRegister()
{
	return UHCP_VPCGCreateHCPGridSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Procedural" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Creates a 2D or 3D Hexagonal Close Packing (HCP) grid of points.\n */" },
#endif
		{ "IncludePath", "HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a 2D or 3D Hexagonal Close Packing (HCP) grid of points." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridExtents_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
		{ "PCG_Overridable", "" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
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
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
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
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
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
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
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
		{ "ModuleRelativePath", "Public/HCP_PCG/Objects/HCP_VPCGCreateHCPMatrixGrid.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, the bounds of the points are set to 50.0, if false, 1.0" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHCP_VPCGCreateHCPGridSettings constinit property declarations ***********
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
// ********** End Class UHCP_VPCGCreateHCPGridSettings constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHCP_VPCGCreateHCPGridSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics

// ********** Begin Class UHCP_VPCGCreateHCPGridSettings Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridExtents = { "GridExtents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPGridSettings, GridExtents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridExtents_MetaData), NewProp_GridExtents_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPGridSettings, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_PointSteepness = { "PointSteepness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPGridSettings, PointSteepness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointSteepness_MetaData), NewProp_PointSteepness_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridPivot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridPivot = { "GridPivot", nullptr, (EPropertyFlags)0x0010000820000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPGridSettings, GridPivot_DEPRECATED), Z_Construct_UEnum_HCP_VPCG_EHCP_VPCGGridPivot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPivot_MetaData), NewProp_GridPivot_MetaData) }; // 576790837
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CoordinateSpace_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CoordinateSpace = { "CoordinateSpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGCreateHCPGridSettings, CoordinateSpace), Z_Construct_UEnum_PCG_EPCGCoordinateSpace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoordinateSpace_MetaData), NewProp_CoordinateSpace_MetaData) }; // 1008406180
void Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_bSetPointsBounds_SetBit(void* Obj)
{
	((UHCP_VPCGCreateHCPGridSettings*)Obj)->bSetPointsBounds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_bSetPointsBounds = { "bSetPointsBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGCreateHCPGridSettings), &Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_bSetPointsBounds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSetPointsBounds_MetaData), NewProp_bSetPointsBounds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_PointSteepness,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridPivot_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_GridPivot,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CoordinateSpace_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_CoordinateSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::NewProp_bSetPointsBounds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::PropPointers) < 2048);
// ********** End Class UHCP_VPCGCreateHCPGridSettings Property Definitions ************************
UObject* (*const Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPCGSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HCP_VPCG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::ClassParams = {
	&UHCP_VPCGCreateHCPGridSettings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::Class_MetaDataParams)
};
void UHCP_VPCGCreateHCPGridSettings::StaticRegisterNativesUHCP_VPCGCreateHCPGridSettings()
{
}
UClass* Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings()
{
	if (!Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.OuterSingleton, Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHCP_VPCGCreateHCPGridSettings);
UHCP_VPCGCreateHCPGridSettings::~UHCP_VPCGCreateHCPGridSettings() {}
// ********** End Class UHCP_VPCGCreateHCPGridSettings *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EHCP_VPCGPointPosition_StaticEnum, TEXT("EHCP_VPCGPointPosition"), &Z_Registration_Info_UEnum_EHCP_VPCGPointPosition, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 470711710U) },
		{ EHCP_VPCGGridPivot_StaticEnum, TEXT("EHCP_VPCGGridPivot"), &Z_Registration_Info_UEnum_EHCP_VPCGGridPivot, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 576790837U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHCP_VPCGCreateHCPGridSettings, UHCP_VPCGCreateHCPGridSettings::StaticClass, TEXT("UHCP_VPCGCreateHCPGridSettings"), &Z_Registration_Info_UClass_UHCP_VPCGCreateHCPGridSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHCP_VPCGCreateHCPGridSettings), 244053252U) },
	};
}; // Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_3937214748{
	TEXT("/Script/HCP_VPCG"),
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Objects_HCP_VPCGCreateHCPMatrixGrid_h__Script_HCP_VPCG_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
