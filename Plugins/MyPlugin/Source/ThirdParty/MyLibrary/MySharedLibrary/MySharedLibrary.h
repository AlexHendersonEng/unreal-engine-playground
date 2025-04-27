#pragma once
#include <string>

#if defined(SHARED_LIBRARY_EXPORT)
	#define SHARED_LIBRARY_API __declspec(dllexport)
#else
	#define SHARED_LIBRARY_API __declspec(dllimport)
#endif

SHARED_LIBRARY_API std::string MySharedLibrary();