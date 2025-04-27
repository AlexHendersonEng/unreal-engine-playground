using System;
using System.IO;
using UnrealBuildTool;
public class MyLibrary : ModuleRules
{
    public MyLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        // Add static libraries
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "out", "install", "x64-release", "lib", "MyStaticLibrary.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "out", "install", "x64-release", "lib", "MySharedLibrary.lib"));

        // Delay-load the DLL, so we can load it from the right place first
        PublicDelayLoadDLLs.Add("MySharedLibrary.dll");

        // Ensure that the DLL is staged along with the executable
        RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "out", "install", "x64-release", "bin", "MySharedLibrary.dll"));
    }
}