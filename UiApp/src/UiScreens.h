#pragma once

#include <iostream>

#include "UiEngine.h"
#include "imgui.h"

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
};