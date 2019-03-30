#pragma once

#ifdef MB_PLATFORM_WINDOWS

extern Marble::Application* Marble::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Marble::CreateApplication();
	app->Run();
	delete app;
}


#endif // MB_PLATFORM_WINDOWS
