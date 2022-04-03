#include <Pulsar.h>

class ExampleLayer : public Pulsar::Layer 
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override 
	{
		if (Pulsar::Input::IsKeyPressed(PR_KEY_TAB))
			PR_TRACE("Tab Key Pressed");
	}

	void OnEvent(Pulsar::Event& event) override 
	{
		if (event.GetEventType() == Pulsar::EventType::KeyPressed) 
		{
			Pulsar::KeyPressedEvent& e = (Pulsar::KeyPressedEvent&)event;
			PR_TRACE("{0}", (char)e.GetKeyCode());
		}
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
