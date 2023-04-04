workspaceName = path.getbasename(os.getcwd())

if (string.lower(workspaceName) == "raylib") then
    print("Cannot use raylib as a workspace name. It is reserved for the raylib library.")
    os.exit()
end

if (workspaceName ~= "RaylibGameTemplate") then
    os.rename("RaylibGameTemplate", workspaceName)
end

print("Creating Raylib template for workspace \"" .. workspaceName .. "\"")

workspace (workspaceName)
    architecture "x86_64"
    startproject (workspaceName)

	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include ("raylib_premake5.lua")
include (workspaceName)