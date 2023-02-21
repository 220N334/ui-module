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
		"%{wks.location}/UiEngine/vendor/GLFW/include",
		"%{wks.location}/UiEngine/vendor/imgui"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		includedirs
		{
			"%{wks.location}/Autofocus/AutoFocus/src",
			"%{wks.location}/Autofocus/AutoFocus/vendor/RaspiCam/src/",
			"/usr/local/include/opencv4"
		}

        links 
		{ 
			"GLFW", 
			"imgui", 
			"Xrandr", 
			"Xi", 
			"GLU", 
			"GL", 
			"X11", 
			"dl", 
			"pthread", 
			"stdc++fs", 
			"opencv_core", 
			"opencv_highgui", 
			"opencv_imgproc", 
			"opencv_imgcodecs", 
			"AutoFocus",  
			"raspicam", 
			"raspicam_cv", 
			"wiringPi", 
			"pthread"
		}
		
        defines { "_X11", "UI_PLATFORM_LINUX" }

	filter "configurations:Debug"
		defines "UI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UI_RELEASE"
		optimize "On"