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
	Autofocus::StepperMotor* motor2;
	Autofocus::StepperMotor* motor3;
	Autofocus::ImageAcquisition* img;
	cv::Mat* frame;
	unsigned char* frameData;

	bool isCameraOpen = false;
	bool stopWindow = false;
private:
	ImGuiWindowFlags window_flags = 0;
	ImFont* mainFont;
	UiEngine::Image image;
};