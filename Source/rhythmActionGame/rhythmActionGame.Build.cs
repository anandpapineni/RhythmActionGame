// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class rhythmActionGame : ModuleRules
{
	public rhythmActionGame(ReadOnlyTargetRules Target) : base(Target)
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
			"rhythmActionGame",
			"rhythmActionGame/Variant_Platforming",
			"rhythmActionGame/Variant_Platforming/Animation",
			"rhythmActionGame/Variant_Combat",
			"rhythmActionGame/Variant_Combat/AI",
			"rhythmActionGame/Variant_Combat/Animation",
			"rhythmActionGame/Variant_Combat/Gameplay",
			"rhythmActionGame/Variant_Combat/Interfaces",
			"rhythmActionGame/Variant_Combat/UI",
			"rhythmActionGame/Variant_SideScrolling",
			"rhythmActionGame/Variant_SideScrolling/AI",
			"rhythmActionGame/Variant_SideScrolling/Gameplay",
			"rhythmActionGame/Variant_SideScrolling/Interfaces",
			"rhythmActionGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
