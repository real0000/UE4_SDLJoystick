// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class SDL2InputLibrary : ModuleRules
{
	public SDL2InputLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
        bEnableUndefinedIdentifierWarnings = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "SDL2.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("SDL2.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/SDL2InputLibrary/Win64/SDL2.dll");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            /*PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
            RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/SDL2InputLibrary/Mac/Release/libExampleLibrary.dylib");*/
        }
	}
}
