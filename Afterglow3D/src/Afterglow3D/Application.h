#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/WindowEvent.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;
	};

	// To be define in EXTERNAL APP
	Application* CreateApplication();
}


