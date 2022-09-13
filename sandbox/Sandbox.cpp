#include "Core/EntryPoint.h"

class Sandbox : public Engine::Core::Application {
public:
	explicit Sandbox(const Engine::Core::ApplicationConfig& config) : Engine::Core::Application(config) {

	}
};

std::unique_ptr<Engine::Core::Application> Engine::Core::CreateApplication() {
	ApplicationConfig config;
	config.windowConfig.Title = "Sandbox App";

	return std::make_unique<Engine::Core::Application>(config);
}