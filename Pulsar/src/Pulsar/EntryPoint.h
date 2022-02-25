#pragma once

#ifdef PR_PLATFORM_WINDOWS

extern Pulsar::Application* Pulsar::CreateApplication();

int main(int argc, char** argv)
{
	printf("Pulsar Engine");
	auto app = Pulsar::CreateApplication();
	app->Run();
	delete app;
}

#endif