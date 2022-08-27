// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AsAboveSoBelow : ModuleRules
{
	public AsAboveSoBelow(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
