#include "Application.h"
#include "EntryPoint.h"

namespace UiEngine
{
	Application::Application(const WindowProps& props)
	{
		Init(props);
	}

	Application::~Application()
	{
		ShutDown();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
			OnUpdate();
			m_Window->OnLastUpdate();
		}
	}

	void Application::Init(const WindowProps& props)
	{
		std::cout << "Hello From Engine" << std::endl;
		m_Window = std::unique_ptr<Window>(Window::Create(props));
	}

	void Application::ShutDown()
	{
		m_Window->Shutdown();
	}
}
