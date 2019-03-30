#pragma once

#include "Core.h"

namespace Marble {

	class MARBLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
