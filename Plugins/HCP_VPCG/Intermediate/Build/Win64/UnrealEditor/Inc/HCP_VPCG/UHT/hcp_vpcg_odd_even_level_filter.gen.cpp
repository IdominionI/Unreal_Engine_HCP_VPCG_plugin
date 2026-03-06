// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h"
#include "Metadata/PCGAttributePropertySelector.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodehcp_vpcg_odd_even_level_filter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_NoRegister();
PCG_API UClass* Z_Construct_UClass_UPCGSettings();
PCG_API UScriptStruct* Z_Construct_UScriptStruct_FPCGAttributePropertyInputSelector();
UPackage* Z_Construct_UPackage__Script_HCP_VPCG();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHCP_VPCGOddEvenLevelFilterSettings **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings;
UClass* UHCP_VPCGOddEvenLevelFilterSettings::GetPrivateStaticClass()
{
	using TClass = UHCP_VPCGOddEvenLevelFilterSettings;
	if (!Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HCP_VPCGOddEvenLevelFilterSettings"),
			Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.InnerSingleton,
			StaticRegisterNativesUHCP_VPCGOddEvenLevelFilterSettings,
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
	return Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_NoRegister()
{
	return UHCP_VPCGOddEvenLevelFilterSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Procedural" },
		{ "IncludePath", "HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridExtents_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BEGIN Added Code+++++++++++++++++++++++++++++++\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BEGIN Added Code+++++++++++++++++++++++++++++++" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//FVector CellSize = FVector(100.0, 100.0, 100.0);\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FVector CellSize = FVector(100.0, 100.0, 100.0);" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetAttribute_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable)) // original code no need to have as a input pin\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta = (PCG_Overridable))  original code no need to have as a input pin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGenerateOutputDataEvenIfEmpty_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings)// original code no need to have as a input pin\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings) original code no need to have as a input pin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasSpatialToPointDeprecation_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Hidden value to indicate that Spatial -> Point deprecation is on where pins are not explicitly points.\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_odd_even_level_filter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hidden value to indicate that Spatial -> Point deprecation is on where pins are not explicitly points." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UHCP_VPCGOddEvenLevelFilterSettings constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridExtents;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetAttribute;
	static void NewProp_bGenerateOutputDataEvenIfEmpty_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerateOutputDataEvenIfEmpty;
	static void NewProp_bHasSpatialToPointDeprecation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasSpatialToPointDeprecation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHCP_VPCGOddEvenLevelFilterSettings constinit property declarations ********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHCP_VPCGOddEvenLevelFilterSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics

// ********** Begin Class UHCP_VPCGOddEvenLevelFilterSettings Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_GridExtents = { "GridExtents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGOddEvenLevelFilterSettings, GridExtents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridExtents_MetaData), NewProp_GridExtents_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGOddEvenLevelFilterSettings, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_TargetAttribute = { "TargetAttribute", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGOddEvenLevelFilterSettings, TargetAttribute), Z_Construct_UScriptStruct_FPCGAttributePropertyInputSelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetAttribute_MetaData), NewProp_TargetAttribute_MetaData) }; // 3844583698
void Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bGenerateOutputDataEvenIfEmpty_SetBit(void* Obj)
{
	((UHCP_VPCGOddEvenLevelFilterSettings*)Obj)->bGenerateOutputDataEvenIfEmpty = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bGenerateOutputDataEvenIfEmpty = { "bGenerateOutputDataEvenIfEmpty", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGOddEvenLevelFilterSettings), &Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bGenerateOutputDataEvenIfEmpty_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGenerateOutputDataEvenIfEmpty_MetaData), NewProp_bGenerateOutputDataEvenIfEmpty_MetaData) };
void Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bHasSpatialToPointDeprecation_SetBit(void* Obj)
{
	((UHCP_VPCGOddEvenLevelFilterSettings*)Obj)->bHasSpatialToPointDeprecation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bHasSpatialToPointDeprecation = { "bHasSpatialToPointDeprecation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGOddEvenLevelFilterSettings), &Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bHasSpatialToPointDeprecation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasSpatialToPointDeprecation_MetaData), NewProp_bHasSpatialToPointDeprecation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_GridExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_TargetAttribute,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bGenerateOutputDataEvenIfEmpty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::NewProp_bHasSpatialToPointDeprecation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::PropPointers) < 2048);
// ********** End Class UHCP_VPCGOddEvenLevelFilterSettings Property Definitions *******************
UObject* (*const Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPCGSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HCP_VPCG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::ClassParams = {
	&UHCP_VPCGOddEvenLevelFilterSettings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::Class_MetaDataParams)
};
void UHCP_VPCGOddEvenLevelFilterSettings::StaticRegisterNativesUHCP_VPCGOddEvenLevelFilterSettings()
{
}
UClass* Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings()
{
	if (!Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.OuterSingleton, Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHCP_VPCGOddEvenLevelFilterSettings);
UHCP_VPCGOddEvenLevelFilterSettings::~UHCP_VPCGOddEvenLevelFilterSettings() {}
// ********** End Class UHCP_VPCGOddEvenLevelFilterSettings ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_odd_even_level_filter_h__Script_HCP_VPCG_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHCP_VPCGOddEvenLevelFilterSettings, UHCP_VPCGOddEvenLevelFilterSettings::StaticClass, TEXT("UHCP_VPCGOddEvenLevelFilterSettings"), &Z_Registration_Info_UClass_UHCP_VPCGOddEvenLevelFilterSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHCP_VPCGOddEvenLevelFilterSettings), 3187235544U) },
	};
}; // Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_odd_even_level_filter_h__Script_HCP_VPCG_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_odd_even_level_filter_h__Script_HCP_VPCG_1896354116{
	TEXT("/Script/HCP_VPCG"),
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_odd_even_level_filter_h__Script_HCP_VPCG_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_odd_even_level_filter_h__Script_HCP_VPCG_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
