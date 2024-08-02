#include "agPCH.h"
#include "WindowsWindow.h"

namespace Afterglow3D
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.m_Title = props.m_Title;
		m_Data.m_Width = props.m_Width;
		m_Data.m_Height = props.m_Height;

		AG_ENGINE_INFO("Creating Window \"{0}\" ({1}, {2})", props.m_Title, props.m_Width, props.m_Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			AG_ENGINE_ASSERT(success, "Unable to initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.m_Width, (int)props.m_Height, props.m_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.m_VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.m_VSync;
	}
}
