#include <iostream>
#include <memory>
#include "Application.h"
#include "../sandbox/src/Sandbox.h"

int main() {
//	auto application = Engine::Application::CreateApplication();

	Engine::ApplicationConfig config {
			.applicationName = "Sandbox"
	};

	auto* application = new Sandbox::SandboxApplication(config);

	application->Run();

	delete application;

	return 0;
}