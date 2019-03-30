#pragma once

#ifdef MB_PLATFORM_WINDOWS

extern Marble::Application* Marble::CreateApplication();

int main(int argc, char** argv)
{
	Marble::Log::Init();
	MB_CORE_WARN("Initialized Log!");
	int a = 5;
	MB_INFO("Hi there. Var={0}",a);
	auto app = Marble::CreateApplication();
	app->Run();
	delete app;
}


#endif // MB_PLATFORM_WINDOWS
