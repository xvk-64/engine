#include "Application.h"

namespace Engine {

	Application* Application::s_instance = nullptr;

	Application::Application(const ApplicationConfig& config)
	: m_config(config),
	m_renderer{Renderer::Create()},
	m_platform{Platform::Create(config.applicationName, config.platformConfig)},
	m_modelManager{}
	{
		if (s_instance != nullptr) {
			// TODO: Put some assert or something here
		}

		s_instance = this;
	}

	void Application::Quit() {
		m_shouldQuit = true;
	}



	void Application::Run() {
		EventHandler<> onQuitHandler {[this](){this->OnWindowClose();}};
		m_platform->GetCurrentWindow().windowCloseEvent.AddHandler(onQuitHandler);

		EventHandler<WindowConfig::WindowSize> onResizeHandler {[this](auto size){this->OnWindowResize(size);}};
		m_platform->GetCurrentWindow().windowResizeEvent.AddHandler(onResizeHandler);

		while (!m_shouldQuit) {
			m_renderer->SetClearColour({0.1f, 0.1f, 0.1f, 1.0f});
			m_renderer->Clear();

			m_world.Update();

			m_platform->GetCurrentWindow().Update();
		}
	}


	void Application::OnWindowClose() {
		Quit();
	}

	void Application::OnWindowResize(const WindowConfig::WindowSize& size) {
		m_renderer->SetViewport(0, 0, size.width, size.height);

		m_world.OnViewportResize(size.width, size.height);
	}
} // Engine