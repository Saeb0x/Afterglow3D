#include "agPCH.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace Afterglow3D
{
#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		/*
			Reminder: When assigning member functions as callbacks, use a lambda or std::bind to
			correctly bind the member function to the current instance.
		*/
		m_Window->SetEventCallback([this](Event& e) {this->OnEvent(e); });
	}

	Application::~Application() {}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher disp(e);
		disp.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));

		for (auto it = m_LayerStack.End(); it != m_LayerStack.Begin();)
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(0.7f, 0.8f, 0.9f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack.GetLayers())
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_IsRunning = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}
}