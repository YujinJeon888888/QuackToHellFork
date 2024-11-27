// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class QuackToHell : ModuleRules
{
	public QuackToHell(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 필요한 모듈 추가: OpenAI, Json, JsonUtilities 
        PublicDependencyModuleNames.AddRange(
            new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "OpenAI", "Json", "JsonUtilities" }
        );


    }
}
