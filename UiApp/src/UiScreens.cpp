#include "UiScreens.h"

UiScreens::UiScreens()
{
	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoBackground;

	ImGuiStyle& style = ImGui::GetStyle();
	style.ItemSpacing.x = 0;
	style.ItemSpacing.y = 0;
	style.WindowPadding.x = 0;
	style.WindowPadding.y = 0;
}

UiScreens::~UiScreens()
{

}

void UiScreens::RenderUi()
{
	//ImGui::ShowDemoWindow();

	switch (screenSelection)
	{
	case 0:
		MainScreen();
		break;
	case 1:
		TestGuideScreen();
		break;
	case 2:
		TestProgressScreen();
		break;
	default:
		break;
	}
}

void UiScreens::MainScreen()
{
	ImGui::Begin("Conteiner", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(800, 480));
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::Dummy(ImVec2(0.0f, 65.0f));
	
	ImGui::Dummy(ImVec2(30.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("START TEST", ImVec2(350, 350)))
	{
		std::cout << "Start" << std::endl;
		screenSelection = 1;
	}
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(40.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("SETTINGS", ImVec2(350, 350)))
	{
		std::cout << "Settings" << std::endl;
	}
	ImGui::End();
}

void UiScreens::TestGuideScreen()
{
	ImGui::Begin("Image Container", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(800, 350));
	ImGui::SetWindowPos(ImVec2(0, 0));

	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
	UiEngine::Image image("images/PixelEngine.png", &my_image_texture, &my_image_width, &my_image_height);
	
	ImGui::Dummy(ImVec2(0.0f, 20.0f));

	ImGui::Dummy(ImVec2(15.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(10.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(10.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::End();
	
	// --------------------------------------------------
	ImGui::Begin("Button Container", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(800, 130));
	ImGui::SetWindowPos(ImVec2(0, 350));
	ImGui::Dummy(ImVec2(100.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("OK", ImVec2(250, 100)))
	{
		std::cout << "OK" << std::endl;
		screenSelection = 2;
	}
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(100.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("BACK", ImVec2(250, 100)))
	{
		std::cout << "BACK" << std::endl;
		screenSelection = 0;
	}
	ImGui::End();
}

void UiScreens::TestProgressScreen()
{
	ImGui::Begin("Unmarked Image Container", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(500, 480));
	ImGui::SetWindowPos(ImVec2(0, 0));

	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
	UiEngine::Image image("images/PixelEngine420.png", &my_image_texture, &my_image_width, &my_image_height);
	
	ImGui::Dummy(ImVec2(0.0f, 30.0f));
	ImGui::Dummy(ImVec2(40.0f, 0.0f));
	ImGui::SameLine();
	ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
	ImGui::End();


	ImGui::Begin("Unmarked Image List Container", NULL, window_flags);
	ImGui::SetWindowSize(ImVec2(300, 480));
	ImGui::SetWindowPos(ImVec2(500, 0));

	const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" };
	static int item_current_idx = 0;
	
	ImGui::Dummy(ImVec2(0.0f, 50.0f));
	ImGui::Dummy(ImVec2(25.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::BeginListBox("##Images", ImVec2(250, 280)))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (item_current_idx == n);
			if (ImGui::Selectable(items[n], is_selected))
				item_current_idx = n;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}

	ImGui::Dummy(ImVec2(0.0f, 25.0f));
	ImGui::Dummy(ImVec2(25.0f, 0.0f));
	ImGui::SameLine();
	if (ImGui::Button("ANALYSE", ImVec2(250, 100)))
	{
		std::cout << "BACK" << std::endl;
		screenSelection = 0;
	}

	ImGui::End();

}
