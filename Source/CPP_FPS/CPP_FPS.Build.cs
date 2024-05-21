// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_FPS : ModuleRules
{
	public CPP_FPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
