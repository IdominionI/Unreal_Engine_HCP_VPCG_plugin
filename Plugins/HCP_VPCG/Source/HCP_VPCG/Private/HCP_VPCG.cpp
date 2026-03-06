// Copyright 2026 Dominion
// Released under the GNU license

#include "HCP_VPCG.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#endif
//#include "VWGlobalSettings.h"

#define LOCTEXT_NAMESPACE "FHCP_VPCGModule"

void FHCP_VPCGModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FHCP_VPCGModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FHCP_VPCGModule, HCP_VPCG)
