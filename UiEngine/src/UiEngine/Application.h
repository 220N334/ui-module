#pragma once

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <memory>

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace UiEngine
{
    class UI_API Application
    {
    public:
        Application(const WindowProps& props);
        virtual ~Application();
        virtual void OnUpdate() = 0;

        virtual void OnCloseEvent(){};

        void Run();
        void OnEvent(Event& e);

        Window& GetWindow() { return *m_Window; }

    private:
        void Init(const WindowProps& props);
        void ShutDown();
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
}
