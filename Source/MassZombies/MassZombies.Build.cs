// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MassZombies : ModuleRules
{
	public MassZombies(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_2;
        
		// List of public dependency module names. These are modules that are required by our public source files
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "MassEntity", "MassSpawner" });

		// List of private dependency module names. These are modules that our private code depends on but nothing in our public include files depend on
		PrivateDependencyModuleNames.AddRange(new string[] { "MassCommon", "StructUtils", "MassMovement", "MassAIBehavior", "MassNavigation" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}