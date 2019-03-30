workspace "Marble"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Marble"
	location "Marble"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MB_PLATFORM_WINDOWS",
			"MB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Marble/vendor/spdlog/include;",
		"Marble/src"
	}

	links
	{
		"Marble"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MB_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "MB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MB_DIST"
		optimize "On"



