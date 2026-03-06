// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HCP_PCG/Filters/hcp_vpcg_surface_filter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodehcp_vpcg_surface_filter() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGSurface_Filter();
HCP_VPCG_API UClass* Z_Construct_UClass_UHCP_VPCGSurface_Filter_NoRegister();
PCG_API UClass* Z_Construct_UClass_UPCGSettings();
UPackage* Z_Construct_UPackage__Script_HCP_VPCG();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UHCP_VPCGSurface_Filter **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter;
UClass* UHCP_VPCGSurface_Filter::GetPrivateStaticClass()
{
	using TClass = UHCP_VPCGSurface_Filter;
	if (!Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HCP_VPCGSurface_Filter"),
			Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.InnerSingleton,
			StaticRegisterNativesUHCP_VPCGSurface_Filter,
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
	return Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.InnerSingleton;
}
UClass* Z_Construct_UClass_UHCP_VPCGSurface_Filter_NoRegister()
{
	return UHCP_VPCGSurface_Filter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Procedural" },
		{ "IncludePath", "HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridExtents_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BEGIN Added Code +++++++++++++++++++++++++++++++\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BEGIN Added Code +++++++++++++++++++++++++++++++" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//FVector CellSize = FVector(100.0, 100.0, 100.0);\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FVector CellSize = FVector(100.0, 100.0, 100.0);" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowerBound_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// END Added Code+++++++++++++++++++++++++++++++\n" },
#endif
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "END Added Code+++++++++++++++++++++++++++++++" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpperBound_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInvertFilter_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bKeepZeroDensityPoints_MetaData[] = {
		{ "Category", "Settings|Debug" },
		{ "ModuleRelativePath", "Public/HCP_PCG/Filters/hcp_vpcg_surface_filter.h" },
		{ "PCG_Overridable", "" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA

// ********** Begin Class UHCP_VPCGSurface_Filter constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridExtents;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowerBound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpperBound;
	static void NewProp_bInvertFilter_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInvertFilter;
#if WITH_EDITORONLY_DATA
	static void NewProp_bKeepZeroDensityPoints_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeepZeroDensityPoints;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHCP_VPCGSurface_Filter constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHCP_VPCGSurface_Filter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics

// ********** Begin Class UHCP_VPCGSurface_Filter Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_GridExtents = { "GridExtents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGSurface_Filter, GridExtents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridExtents_MetaData), NewProp_GridExtents_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGSurface_Filter, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_LowerBound = { "LowerBound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGSurface_Filter, LowerBound), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowerBound_MetaData), NewProp_LowerBound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_UpperBound = { "UpperBound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHCP_VPCGSurface_Filter, UpperBound), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpperBound_MetaData), NewProp_UpperBound_MetaData) };
void Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bInvertFilter_SetBit(void* Obj)
{
	((UHCP_VPCGSurface_Filter*)Obj)->bInvertFilter = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bInvertFilter = { "bInvertFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGSurface_Filter), &Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bInvertFilter_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInvertFilter_MetaData), NewProp_bInvertFilter_MetaData) };
#if WITH_EDITORONLY_DATA
void Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bKeepZeroDensityPoints_SetBit(void* Obj)
{
	((UHCP_VPCGSurface_Filter*)Obj)->bKeepZeroDensityPoints = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bKeepZeroDensityPoints = { "bKeepZeroDensityPoints", nullptr, (EPropertyFlags)0x0010000800002005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHCP_VPCGSurface_Filter), &Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bKeepZeroDensityPoints_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bKeepZeroDensityPoints_MetaData), NewProp_bKeepZeroDensityPoints_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_GridExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_LowerBound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_UpperBound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bInvertFilter,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::NewProp_bKeepZeroDensityPoints,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::PropPointers) < 2048);
// ********** End Class UHCP_VPCGSurface_Filter Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPCGSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_HCP_VPCG,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::ClassParams = {
	&UHCP_VPCGSurface_Filter::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::Class_MetaDataParams), Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::Class_MetaDataParams)
};
void UHCP_VPCGSurface_Filter::StaticRegisterNativesUHCP_VPCGSurface_Filter()
{
}
UClass* Z_Construct_UClass_UHCP_VPCGSurface_Filter()
{
	if (!Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.OuterSingleton, Z_Construct_UClass_UHCP_VPCGSurface_Filter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter.OuterSingleton;
}
UHCP_VPCGSurface_Filter::UHCP_VPCGSurface_Filter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHCP_VPCGSurface_Filter);
UHCP_VPCGSurface_Filter::~UHCP_VPCGSurface_Filter() {}
// ********** End Class UHCP_VPCGSurface_Filter ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_surface_filter_h__Script_HCP_VPCG_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHCP_VPCGSurface_Filter, UHCP_VPCGSurface_Filter::StaticClass, TEXT("UHCP_VPCGSurface_Filter"), &Z_Registration_Info_UClass_UHCP_VPCGSurface_Filter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHCP_VPCGSurface_Filter), 3395392504U) },
	};
}; // Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_surface_filter_h__Script_HCP_VPCG_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_surface_filter_h__Script_HCP_VPCG_1634070919{
	TEXT("/Script/HCP_VPCG"),
	Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_surface_filter_h__Script_HCP_VPCG_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_test_plugin_Plugins_HCP_VPCG_Source_HCP_VPCG_Public_HCP_PCG_Filters_hcp_vpcg_surface_filter_h__Script_HCP_VPCG_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
