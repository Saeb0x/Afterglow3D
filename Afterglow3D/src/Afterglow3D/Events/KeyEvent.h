#pragma once

#include "Event.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class AFTERGLOW3D_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPress)
	private:
		int m_RepeatCount;
	};

	class AFTERGLOW3D_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRelease)
	};
}