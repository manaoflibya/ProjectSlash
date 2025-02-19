// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ShakeSlash : ModuleRules
{
	public ShakeSlash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicIncludePaths.AddRange(
	        new string[]
	        {
        		"ShakeSlash",
		        "ShakeSlash/Mode",
		        "ShakeSlash/Character",
		        "ShakeSlash/Utility",
	        });
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"HeadMountedDisplay",
				"XRBase",
				"UMG",
				"Slate",
				"SlateCore",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				
			});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
