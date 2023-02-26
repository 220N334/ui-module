#pragma once

#include <iostream>

#include "UiEngine.h"
#include "imgui.h"

#ifdef UI_PLATFORM_LINUX
#include AutoFocusHandler.h
#endif

class UiScreens
{
public:
	UiScreens();
	~UiScreens();
	void RenderUi();

private:
	void MainScreen();
	void TestGuideScreen();
	void TestProgressScreen();

	int screenSelection = 0;

	ImGuiWindowFlags window_flags = 0;

#ifdef UI_PLATFORM_LINUX
	AutoFocusHandler af;
#endif
};