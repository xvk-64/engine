#include "Engine.h"

namespace Engine {

	Engine* Engine::s_instance = nullptr;

	Engine::Engine() {
		if (s_instance != nullptr) {
			// TODO: Put some assert or something here
		}

		s_instance = this;

		m_platform = Platform::Create(Platform::PlatformConfig());

	}

	void Engine::Run(Game& game) {
		bool shouldQuit = false;

		EventHandler<> onQuitHandler {[&shouldQuit](){shouldQuit = true;}};
		m_platform->GetCurrentWindow().windowCloseEvent.AddHandler(onQuitHandler);

		while (!shouldQuit) {
			m_platform->GetCurrentWindow().Update();

			if (game.ShouldQuit()) {
				break;
			}
		}
	}
} // Engine