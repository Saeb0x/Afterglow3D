#pragma once

extern Afterglow3D::Application* Afterglow3D::CreateApplication();

#ifdef AG_PLATFORM_WINDOWS
int main(int argc, char* argv[])
{
	auto app = Afterglow3D::CreateApplication();
	app->Run();
	delete app;
}
#endif