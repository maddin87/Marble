#pragma once

#ifdef MB_PLATFORM_WINDOWS
	#ifdef MB_BUILD_DLL
		#define MARBLE_API __declspec(dllexport)
	#else
		#define MARBLE_API __declspec(dllimport)	
	#endif // MB_BUILD_DLL
#else
	#error Marble supports only Windows!
#endif // MB_PLATFORM_WINDOWS
