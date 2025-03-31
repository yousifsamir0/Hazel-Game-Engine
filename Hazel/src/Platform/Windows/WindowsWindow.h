#pragma once
#include "Hazel/Window.h"
#include "Hazel/Log.h"
#include "Hazel/Core.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	class WindowsWindow:public Window
	{
	public:
		WindowsWindow(const WindowProps &props);
		virtual ~WindowsWindow();
		
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; };
		inline unsigned int GetHeight() const override { return m_Data.Height; };

		void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		struct WindowData {
			std::string Title;
			unsigned int Height, Width;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		GLFWwindow* m_Window;
		WindowData m_Data;
	};
}

