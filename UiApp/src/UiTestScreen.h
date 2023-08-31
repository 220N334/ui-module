#pragma once

#include <iostream>

#include "imgui.h"
#include "Utils.h"
#include "UiEngine.h"
#include "AutoFocus.h"

#include <thread>

class UiTestScreens
{
public:
	UiTestScreens();
	~UiTestScreens();
	void RenderTestUi();

	Autofocus::StepperMotor* motor1;
	Autofocus::StepperMotor* motor2;
	Autofocus::StepperMotor* motor3;
	Autofocus::StepperMotor* motor4;

	Autofocus::ImageAcquisition* img;
	cv::Mat* frame;
	unsigned char* frameData;

	bool isCameraOpen = false;
	bool stopWindow = false;
	bool calibrationComplated = false;

	Utils utils;
private:
	ImGuiWindowFlags window_flags = 0;
	ImFont* mainFont;
	UiEngine::Image* image;

	std::thread* streamThread;

	int m_cameraIndex = 0;
};