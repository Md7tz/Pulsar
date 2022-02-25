#pragma once

#include "Core.h"

namespace Pulsar {
	
	class PULSAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

