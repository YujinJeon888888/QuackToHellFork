// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QuackToHell : ModuleRules
{
	public QuackToHell(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","OpenAI" });
	}
}
