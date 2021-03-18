// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FAntlr4RuntimeModule : public IModuleInterface
{
public:
	FAntlr4RuntimeModule();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	#if ANTLR4_STATIC == 0
		void* Antlr4DllHandle;
	#endif
};