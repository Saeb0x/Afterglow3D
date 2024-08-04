#include "agPCH.h"
#include "WindowsWindow.h"

#include "Afterglow3D/Events/WindowEvent.h"
#include "Afterglow3D/Events/KeyEvent.h"
#include "Afterglow3D/Events/MouseEvent.h"

namespace Afterglow3D
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description)
	{
		AG_ENGINE_ERROR("GLFW Error ({0}): {1}", error_code, description);
	}

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

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.m_Width, (int)props.m_Height, props.m_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		SetVSync(true);

		// GLFW Callbacks
		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);
				winData.m_Width = width;
				winData.m_Height = height;

				WindowResizeEvent event(width, height);
				winData.m_EventCallback(event);
			}
		);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				winData.m_EventCallback(event);
			}
		);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressEvent event(key, 0);
						winData.m_EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleaseEvent event(key);
						winData.m_EventCallback(event);
						break;
					}	
					case GLFW_REPEAT:
					{
						KeyPressEvent event(key, 1);
						winData.m_EventCallback(event);
						break;
					}
				}
			}
		);

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressEvent event(button);
						winData.m_EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleaseEvent event(button);
						winData.m_EventCallback(event);
						break;
					}
				}
			}
		);

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrollEvent event((float)xoffset, (float)yoffset);
				winData.m_EventCallback(event);
			}
		);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& winData = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMoveEvent event((float)xpos, (float)ypos);
				winData.m_EventCallback(event);
			}
		);
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
