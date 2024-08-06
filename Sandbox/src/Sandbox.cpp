#include <Afterglow3D.h>

class TestLayer : public Afterglow3D::Layer
{
public:
	TestLayer() : Layer("TestLayer") {}
	
	void OnUpdate() override
	{
		AG_APP_INFO("TestLayer::OnUpdate");
	}

	void OnEvent(Afterglow3D::Event& e) override
	{
		AG_APP_TRACE(e.ToString());
	}
};

class Sandbox : public Afterglow3D::Application
{
public:
	Sandbox() 
	{
		PushLayer(new TestLayer());
	}
	~Sandbox() {}
};

Afterglow3D::Application* Afterglow3D::CreateApplication()
{
	return new Sandbox;
}