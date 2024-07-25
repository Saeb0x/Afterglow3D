#include <Afterglow3D.h>

class Sandbox : public Afterglow3D::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Afterglow3D::Application* Afterglow3D::CreateApplication()
{
	return new Sandbox;
}