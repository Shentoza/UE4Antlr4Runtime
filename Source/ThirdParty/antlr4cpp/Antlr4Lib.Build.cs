// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;

public class Antlr4Lib : ModuleRules
{
	public Antlr4Lib(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		bUseRTTI = true;
		bEnableExceptions = true;
		
		LoadAntlr4Lib(Target);
	}

	public void LoadAntlr4Lib(ReadOnlyTargetRules Target)
	{
		bool LoadStatic = true;
		
		if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
		{
			string LibPlatformDir = Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x32";
			string PlatformDir = Target.Platform.ToString();

			string LibFolder = LoadStatic ? "Release Static" : "Release DLL";
			
			string LibPath = Path.Combine(ModuleDirectory, "lib", LibPlatformDir, LibFolder);

			string FileName = "antlr4-runtime";
			string LibName = FileName + ".lib";
			string DllName = FileName + ".dll";
			
			
			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Release", "ExampleLibrary.lib"));
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "antlr4cpp/lib/vs-2015/x64/Release DLL/antlr4-runtime.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(LibPath, LibName));

			string IncPath = Path.Combine(ModuleDirectory, "include");
			PublicIncludePaths.Add(IncPath);
			PublicSystemIncludePaths.Add(IncPath);
			
			
			PublicDefinitions.Add("WITH_ANTLR4=1");
			if (!LoadStatic)
			{
				string BinaryPath =
					Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../Binaries/ThirdParty", PlatformDir));
				// Delay-load the DLL, so we can load it from the right place first
				PublicDelayLoadDLLs.Add(DllName);

				// Ensure that the DLL is staged along with the executable
				RuntimeDependencies.Add(Path.Combine(BinaryPath, DllName));
				PublicDefinitions.Add("ANTLR4_PLATFORM_PATH=Binaries/ThirdParty/"+PlatformDir);
				PublicDefinitions.Add("ANTLR4_DLL_NAME="+DllName);
				PublicDefinitions.Add("ANTLR4_STATIC=0");
				
			}
			else
			{
				PublicDefinitions.Add("ANTLR4_STATIC=1");
			}
		}
		else
		{
			PublicDefinitions.Add("WITH_ANTLR4=0");
		}
	}
}
