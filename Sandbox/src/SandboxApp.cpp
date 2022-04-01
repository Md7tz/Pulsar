#include <Pulsar.h>

class ExampleLayer : public Pulsar::Layer 
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override 
	{
		//PR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pulsar::Event& event) override 
	{
		PR_TRACE("{0}", event);
	}
};



class Sandbox : public Pulsar::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Pulsar::ImGuiLayer());
	}
	~Sandbox() {}
};

Pulsar::Application* Pulsar::CreateApplication() 
{
	return new Sandbox();
}
