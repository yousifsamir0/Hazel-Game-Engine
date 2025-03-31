#pragma once
#include "Event.h"
#include <sstream>

namespace Hazel {

	class HAZEL_API WindowMovedEvent : public Event{
	
	public:
		WindowMovedEvent(unsigned int x , unsigned int y):m_WindowX(x), m_WindowY(y){}
		inline unsigned int GetWindowX() const {return m_WindowX;}
		inline unsigned int GetWindowY() const {return m_WindowY;}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowMovedEvent: " << "(" << m_WindowX << ", " << m_WindowY << ")";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowMoved)
	private:
		unsigned int m_WindowX, m_WindowY;
	
	};
	class HAZEL_API WindowResizedEvent : public Event{
	
	public:
		WindowResizedEvent(unsigned int height , unsigned int width):m_Height(height), m_Width(width){}
		inline unsigned int GetHeight() const {return m_Height;}
		inline unsigned int GetWidth() const {return m_Width;}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizedEvent: " << "(" << m_Height << ", " << m_Width << ")";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Height, m_Width;
	
	};
	class HAZEL_API WindowCloseEvent : public Event{
	
	public:
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};
	class HAZEL_API AppUpdateEvent : public Event{
	
	public:
		AppUpdateEvent(){}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppUpdateEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};
	class HAZEL_API AppTickEvent : public Event{
	
	public:
		AppTickEvent(){}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppTickEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};
	class HAZEL_API AppRenderEvent : public Event{
	public:
		AppRenderEvent(){}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "AppRenderEvent";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};


}