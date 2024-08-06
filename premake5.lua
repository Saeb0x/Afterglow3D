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

IncludeDir = {}
IncludeDir["GLFW"] = "Afterglow3D/vendor/GLFW/include"

include "Afterglow3D/vendor"

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
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

     filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "AG_PLATFORM_WINDOWS",
            "AG_BUILD_DLL"
        }

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

     filter "configurations:Debug"
        defines {
            "AG_DEBUG",
            "AG_ENABLE_ASSERTS"
        }
        buildoptions "/MDd"
        symbols "On"

     filter "configurations:Release"
        defines "AG_RELEASE"
        buildoptions "/MD"
        optimize "On"

     filter "configurations:Distribution"
        defines "AG_DISTRIBUTION"
        buildoptions "/MD"
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
        defines {
            "AG_DEBUG",
            "AG_ENABLE_ASSERTS"
        }
        buildoptions "/MDd"
        symbols "On"

     filter "configurations:Release"
        defines "AG_RELEASE"
        buildoptions "/MD"
        optimize "On"

     filter "configurations:Distribution"
        defines "AG_DISTRIBUTION"
        buildoptions "/MD"
        optimize "On"