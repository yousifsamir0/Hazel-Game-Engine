#include "Application.h"

namespace Hazel {
	
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window> (Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		bool *isRunning = &m_Running;
		dispatcher.Dispatch<WindowCloseEvent>([isRunning](WindowCloseEvent &e) {
			*isRunning = false;
			return true;
		});
		HZ_INFO(e);
	}

	void Application::Run() 
	{

		
		// application main loop 
		while (m_Running) {

			m_Window->OnUpdate();
		}
	}
}
