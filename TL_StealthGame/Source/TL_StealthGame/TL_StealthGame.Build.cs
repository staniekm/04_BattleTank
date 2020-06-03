// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TL_StealthGame : ModuleRules
{
	public TL_StealthGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule" });
	}
}
