#pragma once 

#include "agPCH.h"
#include "Afterglow3D/Core.h"

namespace Afterglow3D
{
	struct WindowProps
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		WindowProps(const std::string& title = "Afterglow3D Engine", unsigned int width = 1280, unsigned int height = 720)
			: m_Title(title), m_Width(width), m_Height(height) {}
	};

	// Abstract interface representing a desktop system based Window
	class AFTERGLOW3D_API Window
	{
	public:
		static Window* Create(const WindowProps& props = WindowProps());
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual std::string GetTitle() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
	};
}