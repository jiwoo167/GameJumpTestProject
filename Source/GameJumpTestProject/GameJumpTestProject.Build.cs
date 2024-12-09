// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameJumpTestProject : ModuleRules
{
	public GameJumpTestProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "NavigationSystem", "AIModule", "GameplayTasks", "PhysicsCore", "Niagara" });
        PrivateIncludePaths.Add("GameJumpTestProject");

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
