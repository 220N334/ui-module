project "UiApp"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/UiEngine/src",
		"%{wks.location}/UiEngine/vendor/GLFW/include"
	}

	links
	{
		"UiEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UI_PLATFORM_WINDOWS"
		}

	filter "system:linux"
        links { "dl", "pthread" }
        defines { "_X11", "UI_PLATFORM_LINUX" }

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"