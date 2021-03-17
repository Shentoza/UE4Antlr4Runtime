// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Antlr4Lib : ModuleRules
{
	public Antlr4Lib(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "antlr4cpp/lib/vs-2015/x64/Release DLL/antlr4-runtime.lib"));


			PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "antlr4cpp/include"));
			// Delay-load the DLL, so we can load it from the right place first
			//PublicDelayLoadDLLs.Add("ExampleLibrary.dll");
			PublicDelayLoadDLLs.Add("antlr4-runtime.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/antlr4cpp/Win64/antlr4-runtime.dll");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            //PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
            //RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/Antlr4RuntimeLibrary/Mac/Release/libExampleLibrary.dylib");
        }
	}
}
