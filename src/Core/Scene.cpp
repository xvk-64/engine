#include "Scene.h"

namespace Engine {

	void Scene::Update() {
		for (auto& system : m_systems) {
			system->Update();
		}
	}
}