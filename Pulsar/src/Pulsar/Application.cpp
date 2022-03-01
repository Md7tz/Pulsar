#include "Application.h"

#include "Pulsar/Events/ApplicationEvent.h"
#include "Pulsar/Log.h"

namespace Pulsar {

	Application::Application() 
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication)) 
		{
			PR_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PR_TRACE(e);
		}

		while (true);
	}
}