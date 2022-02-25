#pragma once

#ifdef PR_PLATFORM_WINDOWS

extern Pulsar::Application* Pulsar::CreateApplication();

int main(int argc, char** argv)
{
	Pulsar::Log::Init();
	PR_CORE_WARN("Initialized Log!");
	int x = 0;
	PR_INFO("Hello! Var={0}", x);

	auto app = Pulsar::CreateApplication();
	app->Run();
	delete app;
}

#endif