workspace "Game"
	configurations	{ "Debug", "Release" }
	location		"build"
	platforms		{ "x64" }
	characterset	"MBCS"
	startproject	"Game"



project "Game"

	kind		"WindowedApp"
	location	"build/Game"

	files {
				"Game/Source/**.cpp",
				"Game/Source/**.h",
				"GenerateProjectFiles.bat",
				"premake5.lua",
				".gitignore"
	}

	includedirs {
				"Framework/Source",
				"Game/Source",
	}

	links {
				"Framework",
				"opengl32",
	}

project "Framework"
	kind		"StaticLib"
	location	"build/Framework"

	files {
				"Framework/Source/**.cpp",
				"Framework/Source/**.h",
		
	}

	includedirs {
		"Framework/Source",
	}