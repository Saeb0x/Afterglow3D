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

#ifdef AG_ENABLE_ASSERTS
	#define AG_ENGINE_ASSERT(x, ...) { if(!(x)) { AG_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AG_ENGINE_ASSERT(x, ...)
#endif