#pragma once

#include <concepts>
#include <memory>
#include "Platform.h"
#include "World.h"

int main();

namespace Engine {

	// Configuration for Application class
	struct ApplicationConfig {
		std::string applicationName;
		Platform::PlatformConfig platformConfig;
	};

	// Manages initialisation and cleanup of essential engine subsystems.
	class Application {
	public:
		explicit Application(const ApplicationConfig& config);
		virtual ~Application() = default;


		// Quit the application.
		void Quit();

		// Get the current Window.
		Window& GetWindow() {return m_platform->GetCurrentWindow();}


		// Reference to singleton
		static Application& Get() {return *s_instance;}

	private:
		friend int ::main();
		// Start the main behaviour loop
		void Run();


		const ApplicationConfig& m_config;
		std::unique_ptr<Platform> m_platform;
		World m_world;
		bool m_shouldQuit = false;


		static Application* s_instance;
		// Defined in client
		static std::unique_ptr<Application> CreateApplication();
	};

} // Engine
