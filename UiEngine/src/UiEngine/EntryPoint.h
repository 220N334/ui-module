#pragma once

// #ifdef UI_PLATFORM_WINDOWS

extern UiEngine::Application* UiEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = UiEngine::CreateApplication();
	app->Run();
	delete app;
}

// #endif