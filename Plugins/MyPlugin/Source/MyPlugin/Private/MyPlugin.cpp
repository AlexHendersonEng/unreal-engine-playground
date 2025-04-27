// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyPlugin.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "../../ThirdParty/MyLibrary/MyStaticLibrary/MyStaticLibrary.h"
#include "../../ThirdParty/MyLibrary/MySharedLibrary/MySharedLibrary.h"
#define LOCTEXT_NAMESPACE "FMyPluginModule"

void FMyPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    // 
    // Get the base directory of this plugin
    FString BaseDir = IPluginManager::Get().FindPlugin("MyPlugin")->GetBaseDir();

    // Add on the relative location of the third party dll and load it
    FString MyLibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/MyLibrary/out/install/x64-release/bin/MySharedLibrary.dll"));
    MyLibraryHandle = !MyLibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*MyLibraryPath) : nullptr;
    if (MyLibraryHandle)
    {
        // Some code that will be executed if dll was found
    }
    else
    {
        FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load MySharedLibrary"));
    }
}

void FMyPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

    // Free the dll handle
    FPlatformProcess::FreeDllHandle(MyLibraryHandle);
    MyLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FMyPluginModule, MyPlugin)