#pragma once
#include "UiEngine/Core.h"
#include "Event.h"
#include <sstream>

namespace UiEngine
{
	class UI_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}