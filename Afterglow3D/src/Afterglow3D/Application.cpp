#include "agPCH.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Afterglow3D
{
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(0.7f, 0.8f, 0.9f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}