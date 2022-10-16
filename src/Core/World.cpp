#include "World.h"

namespace Engine {

	void World::Update() {
		if (m_currentScene) {
			m_currentScene->Update(*this);
		}

		// If there is a new scene to switch to, switch to it.
		if (m_nextScene) {
			if (m_currentScene)
				// Detach the current scene
				m_currentScene->OnDetach(*this);

			m_currentScene = std::move(m_nextScene);

			// Attach the new scene
			m_currentScene->OnAttach(*this);
		}
	}
}