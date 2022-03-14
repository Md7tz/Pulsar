workspace "Pulsar"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (sln)
IncludeDirs = {}
IncludeDirs["GLFW"] = "Pulsar/vendor/GLFW/include"
IncludeDirs["Glad"] = "Pulsar/vendor/Glad/include"

include "Pulsar/vendor/GLFW"
include "Pulsar/vendor/Glad"

project "Pulsar"
	location "Pulsar" 
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("!obj/" .. outputdir .. "/%{prj.name}")

	pchheader "prpch.h"
	pchsource "Pulsar/src/prpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines 
		{
			"PR_PLATFORM_WINDOWS",
			"PR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"	
		}

		postbuildcommands 
		{
			("{MKDIR} %{wks.location}bin/" .. outputdir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
		defines 
		{
			"PR_ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		defines "PR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("!obj/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Pulsar/src",
		"Pulsar/vendor/spdlog/include"
	}

	links 
	{
		"Pulsar"	
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines 
		{
			"PR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

		defines 
		{
			"PR_ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		defines "PR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		buildoptions "/MD"
		optimize "On"