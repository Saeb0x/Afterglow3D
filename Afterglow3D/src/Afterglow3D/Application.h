#pragma once

#include "Core.h"
#include "Window.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	// To be define in EXTERNAL APP
	Application* CreateApplication();
}


