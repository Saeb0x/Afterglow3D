project "GLFW"
    kind "StaticLib"
    language "C"
    staticruntime "On"
    warnings "Off"
    
outputDir = "%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files {
        "GLFW/include/GLFW/glfw3.h",
        "GLFW/include/GLFW/glfw3native.h",
        "GLFW/src/context.c",
        "GLFW/src/init.c",
        "GLFW/src/input.c",
        "GLFW/src/monitor.c",

        "GLFW/src/null_init.c",
        "GLFW/src/null_joystick.c",
        "GLFW/src/null_window.c",
        "GLFW/src/null_monitor.c",
        
        "GLFW/src/platform.c",
        "GLFW/src/window.c",
        "GLFW/src/vulkan.c"
    }

    filter "system:windows"
        systemversion "latest"

        files {
            "GLFW/src/win32_init.c",
            "GLFW/src/win32_joystick.c",
            "GLFW/src/win32_module.c",
            "GLFW/src/win32_monitor.c",
            "GLFW/src/win32_time.c",
            "GLFW/src/win32_thread.c",
            "GLFW/src/win32_window.c",
            "GLFW/src/wgl_context.c",
            "GLFW/src/egl_context.c",
            "GLFW/src/osmesa_context.c",
        }

        defines {
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "speed"

    filter "configurations:Distribution"
        runtime "Release"
        optimize "speed"
        symbols "Off"