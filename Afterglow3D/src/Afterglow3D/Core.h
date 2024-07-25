#pragma once

#ifdef AG_PLATFORM_WINDOWS
	#ifdef AG_BUILD_DLL
		#define AFTERGLOW3D_API __declspec(dllexport)
	#else
		#define AFTERGLOW3D_API __declspec(dllimport)
	#endif
#else
	#error Afterglow only supports Windows!
#endif