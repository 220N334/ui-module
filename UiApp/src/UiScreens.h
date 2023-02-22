#pragma once

#include <iostream>

#include "UiEngine.h"
#include "imgui.h"
#include "AutoFocus.h"

class UiScreens
{
public:
	UiScreens();
	~UiScreens();
	void RenderUi();

	Autofocus::StepperMotor* motor1;
private:
	void MainScreen();
	void TestGuideScreen();
	void TestProgressScreen();

	int screenSelection = 0;

	ImGuiWindowFlags window_flags = 0;
};