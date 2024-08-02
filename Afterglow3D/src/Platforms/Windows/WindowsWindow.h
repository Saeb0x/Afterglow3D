#pragma once

#include "Afterglow3D/Window.h"

#include <GLFW/glfw3.h>

namespace Afterglow3D
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		
		std::string GetTitle() const override { return m_Data.m_Title; }
		unsigned int GetWidth() const override { return m_Data.m_Width; }
		unsigned int GetHeight() const override { return m_Data.m_Height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string m_Title;
			unsigned int m_Width;
			unsigned int m_Height;
			bool m_VSync;
		};

		WindowData m_Data;
	};
}

