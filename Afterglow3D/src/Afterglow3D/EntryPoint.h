#pragma once

#ifdef AG_PLATFORM_WINDOWS

extern Afterglow3D::Application* Afterglow3D::CreateApplication();

int main(int argc, char* argv[])
{
	Afterglow3D::Log::Init();

	AG_ENGINE_WARN("Initialized Log!");

	auto app = Afterglow3D::CreateApplication();
	app->Run();
	delete app;
}
#endif