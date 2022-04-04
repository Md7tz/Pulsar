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
IncludeDirs["ImGui"] = "Pulsar/vendor/ImGui"
IncludeDirs["glm"] = "Pulsar/vendor/glm"

group "Dependencies"
	include "Pulsar/vendor/GLFW"
	include "Pulsar/vendor/Glad"
	include "Pulsar/vendor/ImGui"

project "Pulsar"
	location "Pulsar" 
	kind "SharedLib"
	staticruntime "Off"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("!obj/" .. outputdir .. "/%{prj.name}")

	pchheader "prpch.h"
	pchsource "Pulsar/src/prpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}",
		"%{IncludeDirs.ImGui}",
		"%{IncludeDirs.glm}"
	}

	links 
	{
		"GLFW",
		"Glad",
		'ImGui',
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"PR_PLATFORM_WINDOWS",
			"PR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"	
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		runtime "Debug"
		symbols "On"
		
		defines 
		{
			"PR_ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		defines "PR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	staticruntime "Off"
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
		"Pulsar/vendor/spdlog/include",
		"%{IncludeDirs.glm}"
	}

	links 
	{
		"Pulsar"	
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines 
		{
			"PR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		runtime "Release"
		optimize "On"