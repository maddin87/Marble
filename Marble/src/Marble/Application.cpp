#include "Application.h"

#include "Marble/Events/ApplicationEvent.h"
#include "Marble/Log.h"

namespace Marble {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		MB_TRACE(e);

		while (true);
	}
}