#include "World.h"

namespace Engine {

	void World::Update() {
		if (m_currentScene)
			m_currentScene->Update();
	}
}