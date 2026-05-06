// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActionGamePrototype : ModuleRules
{
	public ActionGamePrototype(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"UMG", 
			"CogCommon"
		});
		
		// Other Cog plugins can be added only for specific target configuration
		if (Target.Configuration != UnrealTargetConfiguration.Shipping)
		{
			PublicDependencyModuleNames.AddRange(new string[]
			{
				"Cog",
				"CogAbility",
				"CogAI",
				"CogAll",
				"CogDebug",
				"CogEngine",
				"CogImgui",
				"CogInput",
			});
		}
	}
}
