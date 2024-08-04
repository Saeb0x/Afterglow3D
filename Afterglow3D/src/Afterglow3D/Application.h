#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Events/WindowEvent.h"

#include "Window.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	// To be define in EXTERNAL APP
	Application* CreateApplication();
}


