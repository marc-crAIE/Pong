project "raylib"
    kind "StaticLib"
    language "C"
    location "raylib"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs
    {
        "raylib/src",
        "raylib/src/external/glfw/include"
    }

    vpaths
    {
        ["Header Files"] = { "raylib/src/**.h" },
        ["Source Files/*"] = { "raylib/src/**.c" },
    }
    
    defines { "PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_43" }
    
    files { "raylib/src/*.h", "raylib/src/*.c" }

    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        characterset ("MBCS")
        
    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "NDEBUG", "RELEASE" }
        runtime "Release"
        optimize "on"