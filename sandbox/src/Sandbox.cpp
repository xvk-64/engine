#include "SandboxScene.h"

namespace Sandbox {
	class SandboxApplication : public Engine::Application {
	public:
		explicit SandboxApplication(const Engine::ApplicationConfig& config) : Application(config) {
			auto scene = std::make_unique<SandboxScene>();

			GetWorld().SwitchScene(std::move(scene));
		}
	};
}

std::unique_ptr<Engine::Application> Engine::Application::CreateApplication() {
	ApplicationConfig config {
		.applicationName = "Sandbox"
	};

	return std::make_unique<Sandbox::SandboxApplication>(config);
}