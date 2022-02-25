#include <Pulsar.h>

class Sandbox : public Pulsar::Application 
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Pulsar::Application* Pulsar::CreateApplication() 
{
	return new Sandbox();
}
