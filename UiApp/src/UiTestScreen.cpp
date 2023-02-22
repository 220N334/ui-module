#include "UiTestScreen.h"

static int mAngle = 360;
static int mSpeed = 300;
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
    motor1Pins.step = 2;
    motor1Pins.en = 1;
    motor1Pins.dir = 0;
    motor1Pins.ms1 = 0;
    motor1Pins.ms1 = 0;

	motor1 = new Autofocus::StepperMotor(motor1Pins);
	img = new Autofocus::ImageAcquisition();
}

UiTestScreens::~UiTestScreens()
{
	delete(motor1);
	delete(img);
}

void UiTestScreens::RenderTestUi()
{
	//ImGui::ShowDemoWindow();
    ImGui::Begin("Motor", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(500, 480));
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowFontScale(4.0f);
	
	ImGui::PushItemWidth(300);
	ImGui::Dummy(ImVec2(0.0f, 30.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::InputInt("A", &mAngle, 10);

	ImGui::Dummy(ImVec2(0.0f, 50.0f));
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::InputInt("S", &mSpeed, 10);

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

	}
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("M3", ImVec2(100, 100)))
	{

	}
	ImGui::End();

	ImGui::Begin("Image", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(400, 480));
	ImGui::SetWindowPos(ImVec2(400, 0));
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
	UiEngine::Image image("img.png", &my_image_texture, &my_image_width, &my_image_height);
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Dummy(ImVec2(0.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	ImGui::Dummy(ImVec2(100.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("CAPTURE", ImVec2(200, 100)))
	{
		cv::Mat* frame = new cv::Mat;
        img->CaptureImage(frame);
		cv::imwrite("img1.png", *frame);
		img->ResizeImage(frame, 250, 300);
        cv::imwrite("img.png", *frame);
        delete(frame);
	}
	ImGui::End();
}
