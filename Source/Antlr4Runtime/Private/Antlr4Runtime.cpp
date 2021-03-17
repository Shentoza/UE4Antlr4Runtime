// Copyright Epic Games, Inc. All Rights Reserved.

#include "Antlr4Runtime.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FAntlr4RuntimeModule"

void FAntlr4RuntimeModule::StartupModule()
{
}

void FAntlr4RuntimeModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAntlr4RuntimeModule, Antlr4Runtime)
