#include "Application.h"
#include "EntryPoint.h"

namespace UiEngine
{
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

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

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Init(const WindowProps& props)
	{
		std::cout << "Hello From Engine" << std::endl;
		m_Window = std::unique_ptr<Window>(Window::Create(props));
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::ShutDown()
	{
		m_Window->Shutdown();
	}
}
