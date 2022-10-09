#include "Core/EntryPoint.h"

class SandboxApplication : public Engine::Application {
public:
	explicit SandboxApplication(const Engine::ApplicationConfig& config) : Application(config) {

	}
};

std::unique_ptr<Engine::Application> Engine::Application::CreateApplication() {
	ApplicationConfig config {
		.applicationName = "Sandbox"
	};

	return std::make_unique<SandboxApplication>(config);
}