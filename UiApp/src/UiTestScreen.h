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
	Autofocus::ImageAcquisition* img;
	cv::Mat* frame;

	bool isCameraOpen = false;
	bool stopWindow = false;
private:
	ImGuiWindowFlags window_flags = 0;
};