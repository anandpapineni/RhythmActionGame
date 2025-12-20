// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RhythmActionGame : ModuleRules
{
	public RhythmActionGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"RhythmActionGame",
			"RhythmActionGame/Variant_Platforming",
			"RhythmActionGame/Variant_Platforming/Animation",
			"RhythmActionGame/Variant_Combat",
			"RhythmActionGame/Variant_Combat/AI",
			"RhythmActionGame/Variant_Combat/Animation",
			"RhythmActionGame/Variant_Combat/Gameplay",
			"RhythmActionGame/Variant_Combat/Interfaces",
			"RhythmActionGame/Variant_Combat/UI",
			"RhythmActionGame/Variant_SideScrolling",
			"RhythmActionGame/Variant_SideScrolling/AI",
			"RhythmActionGame/Variant_SideScrolling/Gameplay",
			"RhythmActionGame/Variant_SideScrolling/Interfaces",
			"RhythmActionGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
