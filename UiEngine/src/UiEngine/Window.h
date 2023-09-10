#pragma once

#include <string>
#include <functional>

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace UiEngine
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps
		(
			const std::string& title = "UiEngine",
			unsigned int width = 1280,
			unsigned int height = 720
		)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class UI_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};
		virtual void OnUpdate() = 0;
		virtual void OnLastUpdate() = 0;
		virtual void Shutdown() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeigth() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const WindowProps& props);
	};
}