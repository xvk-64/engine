#include "Application.h"

namespace Engine {

	Application* Application::s_instance = nullptr;

	Application::Application(const ApplicationConfig& config)
	: m_config(config) {
		if (s_instance != nullptr) {
			// TODO: Put some assert or something here
		}

		s_instance = this;

		m_platform = Platform::Create(config.applicationName, config.platformConfig);

		m_renderer = Renderer::Create();
	}

	void Application::Quit() {
		m_shouldQuit = true;
	}

	void Application::Run() {
		EventHandler<> onQuitHandler {[this](){m_shouldQuit = true;}};
		m_platform->GetCurrentWindow().windowCloseEvent.AddHandler(onQuitHandler);

		while (!m_shouldQuit) {
			m_renderer->SetClearColour({0.1f, 0.1f, 0.1f, 1.0f});
			m_renderer->Clear();

			m_world.Update();

			m_platform->GetCurrentWindow().Update();
		}
	}
} // Engine