workspace "Afterglow3D"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

	-- Only supported by Visual Studio --
	startproject "Sandbox"
	-------------------------------------

outputDir = "%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}"

project "Afterglow3D"
	location "Afterglow3D"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "agPCH.h"
	pchsource "Afterglow3D/src/agPCH.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AG_PLATFORM_WINDOWS",
			"AG_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "AG_DISTRIBUTION"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Afterglow3D/vendor/spdlog/include",
		"Afterglow3D/src"
	}

	links {
		"Afterglow3D"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"AG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AG_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "AG_DISTRIBUTION"
		optimize "On"