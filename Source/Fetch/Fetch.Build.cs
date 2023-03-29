// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Fetch : ModuleRules
{
    public Fetch(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PrecompileForTargets = PrecompileTargetsType.Any;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            "HTTP",
            "Json",
            "JsonUtilities"
        });
    }
}

