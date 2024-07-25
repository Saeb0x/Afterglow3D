#pragma once

#include "Core.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in EXTERNAL APP
	Application* CreateApplication();
}


