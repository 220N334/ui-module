#include "UiTestScreen.h"

static int mAngle = 50;
static int mSpeed = 2500;
static int mDir = 0;

UiTestScreens::UiTestScreens()
{
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoBackground;

	ImGuiStyle& style = ImGui::GetStyle();
	style.ItemSpacing.x = 0;
	style.ItemSpacing.y = 0;
	style.WindowPadding.x = 0;
	style.WindowPadding.y = 0;

	Autofocus::StepperPins motor1Pins;
    motor1Pins.step = 28;
    motor1Pins.en = 29;
    motor1Pins.dir = 27;
    motor1Pins.ms1 = 0;
    motor1Pins.ms1 = 0;

	Autofocus::StepperPins motor2Pins;
    motor2Pins.step = 31;
    motor2Pins.en = 26;
    motor2Pins.dir = 11;
    motor2Pins.ms1 = 0;
    motor2Pins.ms1 = 0;

	Autofocus::StepperPins motor3Pins;
    motor3Pins.step = 6;
    motor3Pins.en = 10;
    motor3Pins.dir = 5;
    motor3Pins.ms1 = 0;
    motor3Pins.ms1 = 0;

	Autofocus::StepperPins motor4Pins;
    motor4Pins.step = 1;
    motor4Pins.en = 4;
    motor4Pins.dir = 16;
    motor4Pins.ms1 = 0;
    motor4Pins.ms1 = 0;

	motor1 = new Autofocus::StepperMotor(motor1Pins);
	motor2 = new Autofocus::StepperMotor(motor2Pins);
	motor3 = new Autofocus::StepperMotor(motor3Pins);
	motor4 = new Autofocus::StepperMotor(motor4Pins);
	
	img = new Autofocus::ImageAcquisition();
	isCameraOpen = img->OpenCamera();
    // cv::Mat blueImage(100, 100, CV_8UC3, cv::Scalar(255, 0, 0));
	frame = new cv::Mat;
	image = new UiEngine::Image();

	ImGuiIO& io = ImGui::GetIO();
	mainFont = io.Fonts->AddFontFromFileTTF("fonts/Roboto-Medium.ttf", 40.0);

	//streamThread = new std::thread(&Utils::StreamLoop, std::ref(utils), img, frame, image);
	motor3->RunMotor(0, 450, 2500);
}

UiTestScreens::~UiTestScreens()
{
	img->ReleaseCamera();
	delete(motor1);
	delete(motor2);
	delete(motor3);
	delete(motor4);
	delete(img);
    delete(frame);
	delete(frameData);
	delete(image);
}

void UiTestScreens::RenderTestUi()
{
	//ImGui::ShowDemoWindow();
	ImGui::PushFont(mainFont);
    ImGui::Begin("Motor", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(500, 480));
	ImGui::SetWindowPos(ImVec2(0, 0));
	// ImGui::SetWindowFontScale(4.0f);
	
	ImGui::PushItemWidth(300);
	ImGui::Dummy(ImVec2(0.0f, 30.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::InputInt("A", &mAngle, 1);

	ImGui::Dummy(ImVec2(0.0f, 50.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::InputInt("S", &mSpeed, 100);

	ImGui::Dummy(ImVec2(0.0f, 50.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::InputInt("D", &mDir, 1);
    if(mDir > 1)
    {
        mDir = 1;
    }
    else if(mDir < 0)
    {
        mDir = 0;
    }

	ImGui::Dummy(ImVec2(0.0f, 50.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("M1", ImVec2(100, 100)))
	{
        motor1->RunMotor(mDir, mAngle, mSpeed);
	}
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("M2", ImVec2(100, 100)))
	{
		motor2->RunMotor(mDir, mAngle, mSpeed);
	}
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("M3", ImVec2(100, 100)))
	{
		motor3->RunMotor(mDir, mAngle, mSpeed);
	}
	ImGui::End();
	//----------------------------------------------------------
	ImGui::Begin("Image", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(400, 480));
	ImGui::SetWindowPos(ImVec2(400, 0));
	ImGui::Dummy(ImVec2(340.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("X", ImVec2(40, 40)))
	{
		//m_Running = false;
		stopWindow = true;
	}

	//ImGui::Dummy(ImVec2(0.0f, 20.0f));
	//int my_image_width = 0;
	//int my_image_height = 0;
	//GLuint my_image_texture = 0;
	//bool imageLoaded = image.LoadTextureFromFile("img.png", &my_image_texture, &my_image_width, &my_image_height);
    //if (!imageLoaded)
    //{
    //    std::cout << "Image Load Failed" << std::endl;
    //}

	img->CaptureImage(frame);
	frameData = new unsigned char[frame->total() * frame->elemSize()];
	std::memcpy(frameData, frame->data, frame->total() * frame->elemSize());
	image->ShowVideoFromImage(frameData, &frame->cols, &frame->rows);

	if(!calibrationComplated)
	{
		calibrationComplated = utils.FocusAlgorithm(frame, motor4);
	}

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Dummy(ImVec2(0.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)image->GetTextureID(), ImVec2(frame->rows, frame->cols));
	ImGui::Dummy(ImVec2(0.0f, 10.0f));
	ImGui::Dummy(ImVec2(100.0f, 0.0f));
	ImGui::SameLine();

	if (ImGui::Button("CAPTURE", ImVec2(200, 100)))
	{
		if(isCameraOpen)
		{
			//img->CaptureImage(frame);
			std::string imgName 		=  std::to_string(m_cameraIndex) + ".png";
			std::string imgNameResized 	=  "Resized" + std::to_string(m_cameraIndex) + ".png";

			cv::imwrite(imgName, *frame);
			img->ResizeImage(frame, 400, 300);
			cv::imwrite(imgNameResized, *frame);

			m_cameraIndex += 1;
		}
	}
	ImGui::End();
	ImGui::PopFont();
}