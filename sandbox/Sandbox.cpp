#include "Core/EntryPoint.h"

class Sandbox : public Engine::Core::Application {
public:
	explicit Sandbox(const Engine::Core::ApplicationConfig& config) : Engine::Core::Application(config) {

	}
};

std::unique_ptr<Engine::Core::Application> Engine::Core::CreateApplication() {
	ApplicationConfig config {
		.windowConfig = {
			.windowTitle = "Sandbox",
			.windowSize = glm::ivec2(640, 480),
		}
	};

	return std::make_unique<Engine::Core::Application>(config);
}