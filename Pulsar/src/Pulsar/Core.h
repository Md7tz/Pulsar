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

#define BIT(x) (1 << x)