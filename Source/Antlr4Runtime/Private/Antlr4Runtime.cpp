// Copyright Epic Games, Inc. All Rights Reserved.

#include "Antlr4Runtime.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FAntlr4RuntimeModule"

FAntlr4RuntimeModule::FAntlr4RuntimeModule() : Antlr4DllHandle(nullptr)
{
}

void FAntlr4RuntimeModule::StartupModule()
{
#if WITH_ANTLR4
	#if ANTLR4_STATIC == 0
		const FString PluginDir = IPluginManager::Get().FindPlugin(TEXT("Antlr4Runtime"))->GetBaseDir();
		const FString Antlr4BinPath = PluginDir / TEXT(PREPROCESSOR_TO_STRING(ANTLR4_PLATFORM_PATH));
		const FString DLLPath = Antlr4BinPath/ TEXT(PREPROCESSOR_TO_STRING(ANTLR4_DLL_NAME));

		FPlatformProcess::PushDllDirectory(*Antlr4BinPath);
		Antlr4DllHandle = FPlatformProcess::GetDllHandle(*DLLPath);
		FPlatformProcess::PopDllDirectory(*Antlr4BinPath);
	#endif
#endif
}

void FAntlr4RuntimeModule::ShutdownModule()
{
#if WITH_ANTLR4
	#if ANTLR4_STATIC == 0
		if(Antlr4DllHandle)
		{
			FPlatformProcess::FreeDllHandle(Antlr4DllHandle);
			Antlr4DllHandle = nullptr;
		}
	#endif
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAntlr4RuntimeModule, Antlr4Runtime)
