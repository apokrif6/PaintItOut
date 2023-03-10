// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PaintItOut : ModuleRules
{
	public PaintItOut(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
