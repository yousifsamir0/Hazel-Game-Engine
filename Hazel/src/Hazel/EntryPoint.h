#pragma once
#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char* argv) {
	Hazel::Log::Init();

	//HZ_CORE_INFO("hello from core logger");
	//HZ_TRACE("hello from core logger");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;

}
#endif // HZ_PATFORM_WINDOWS
