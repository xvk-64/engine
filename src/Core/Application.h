#pragma once

#include <concepts>
#include <memory>
#include "Platform.h"
#include "World.h"
#include "Graphics/Renderer.h"
#include "Graphics/ModelManager.h"

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
		Application() = delete;
		explicit Application(const ApplicationConfig& config);
		virtual ~Application() = default;


		// Quit the application.
		void Quit();

		// Get the current Window.
		Window& GetWindow() {return m_platform->GetCurrentWindow();}
		// Get the current Input
		Input& GetInput() {return m_platform->GetInput();}

		// Get the current Renderer
		Renderer& GetRenderer() {return *m_renderer;}

		ModelManager& GetModelManager() {return m_modelManager;}

		World& GetWorld() {return m_world;}


//		// Reference to singleton
//		static Application& Get() {return *s_instance;}

	private:
		friend int ::main();
		// Start the main behaviour loop
		void Run();

		void OnWindowClose();
		void OnWindowResize(const WindowConfig::WindowSize& size);


		const ApplicationConfig& m_config;
		std::unique_ptr<Platform> m_platform;
		std::unique_ptr<Renderer> m_renderer;
		ModelManager m_modelManager;
		World m_world;
		bool m_shouldQuit = false;


		static Application* s_instance;
		// Defined in client
		static std::unique_ptr<Application> CreateApplication();
	};

} // Engine
