#include "Application.h"
#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() 
	{
		// initializations
		WindowResizedEvent e(1280, 720);
		HZ_TRACE(e);
		HZ_INFO(e);

		
		// application main loop 
		while (true);
	}
}
