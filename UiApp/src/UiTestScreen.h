#pragma once

#include <iostream>

#include "imgui.h"
#include "UiEngine.h"
#include "AutoFocus.h"

class UiTestScreens
{
public:
	UiTestScreens();
	~UiTestScreens();
	void RenderTestUi();

	Autofocus::StepperMotor* motor1;
private:
	ImGuiWindowFlags window_flags = 0;
};