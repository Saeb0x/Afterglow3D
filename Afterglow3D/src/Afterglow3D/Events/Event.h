#pragma once

#include "agPCH.h"
#include "Afterglow3D/Core.h"

namespace Afterglow3D
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
	};

	// For filtering purposes
	enum EventCategory
	{
		None = 0, 
		EventCategoryWindow = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryMouse = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouseRelease = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticEventType() { return EventType::##type; }\
								EventType GetEventType() const override { return GetStaticEventType(); }\
								const char* GetName() const override { return #type; }
								
#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; }

	class AFTERGLOW3D_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool IsHandled() const { return m_Handled; }
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticEventType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}