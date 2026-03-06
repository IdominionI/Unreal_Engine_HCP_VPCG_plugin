// Copyright 2026 Dominion
// Released under the GNU license

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_CLASS(LogHCP_VPCG, Log, All)

class FHCP_VPCGModule final : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
