workspace "Game"
	configurations { "Debug", "Release" }
	location "build"

	platforms { "x64" }
	characterset "MBCS"



project "Game"

	kind "WindowedApp"

	files {
		"Game/Source/**.cpp",
		"GenerateProjectFiles.bat",
		"premake5.lua",
		".gitignore"
	}