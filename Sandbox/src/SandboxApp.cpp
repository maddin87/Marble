#include <Marble.h>


class Sandbox : public Marble::Application 
{
public:
	Sandbox(){}

	~Sandbox(){}
};

Marble::Application* Marble::CreateApplication()
{
	return new Sandbox();
}