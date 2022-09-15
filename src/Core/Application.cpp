//
// Created by valen on 10/09/2022.
//

#include <iostream>
#include "Application.h"

namespace Engine::Core {

	Application::Application(const ApplicationConfig& config) {
		m_platform = Platform::Platform::Create(config.windowConfig);

		m_platform->GetWindow().WindowCloseEvent.AddHandler(m_handleOnWindowClose);
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_running) {
			m_platform->GetWindow().OnUpdate();
		}
	}
}
