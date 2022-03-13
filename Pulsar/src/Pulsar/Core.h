#pragma once

#ifdef PR_PLATFORM_WINDOWS
	#ifdef PR_BUILD_DLL
		#define PULSAR_API __declspec(dllexport)
	#else
		#define PULSAR_API __declspec(dllimport)
	#endif
#else
	#error Pulsar only supports windows!
#endif

#ifdef PR_ENABLE_ASSERTS
	#define PR_CORE_ASSERT(x, ...) { if(!(x)) { PR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }} 
	#define PR_ASSERT(x, ...) { if(!(x)) { PR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define PR_CORE_ASSERT(x, ...)
	#define PR_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)