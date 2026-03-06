// Copyright 2026 Dominion
// Released under the GNU license

using UnrealBuildTool;

public class HCP_VPCG : ModuleRules
{
	public HCP_VPCG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//bUseUnity = true;

		PublicIncludePaths.AddRange(
			new string[]
			{
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				//"ThirdParty/Delaunator/include"
			}
		);


		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"GeometryScriptingCore",
				"PCG",
				"PCGGeometryScriptInterop"
            }
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"RenderCore",
				"RHI",
				"GeometryCore",
				"GeometryFramework",
				"GeometryAlgorithms",
				"PhysicsCore",
				"NavigationSystem",
				"Slate",
				"SlateCore",
				"GameplayTags",
				"PropertyPath",
				"DeveloperSettings"
                   // "ModelingComponents"// ++++
            }
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
