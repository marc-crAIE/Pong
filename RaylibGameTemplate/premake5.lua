project (workspaceName)
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    vpaths 
	{
	  ["Header Files/*"] = { "include/**.h",  "include/**.hpp", "src/**.h", "src/**.hpp", "**.h", "**.hpp" },
	  ["Source Files/*"] = {"src/**.c", "src/**.cpp","**.c", "**.cpp" }
	}

	files
	{
		"src/**.h",
        "src/**.hpp",
        "src/**.c",
		"src/**.cpp"
	}

    includedirs
    {
        "%{wks.location}/raylib/src",
        "%{wks.location}/raylib/src/external",
        "%{wks.location}/raylib/src/external/glfw/include",
        "src"
    }

    links
    {
        "raylib"
    }

    defines { "PLATFORM_DESKTOP", "GRAPHICS_API_OPENGL_43" }

    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        dependson {"raylib"}
        links {"raylib.lib"}
        characterset ("MBCS")
        
    filter "system:windows"
        systemversion "latest"
        defines{"_WIN32"}
        links {"winmm", "kernel32", "opengl32", "gdi32"}
        libdirs {"%{wks.location}/bin/" .. outputdir .. "/raylib"}

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "NDEBUG", "RELEASE" }
        runtime "Release"
        optimize "on"