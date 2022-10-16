#include "Scene.h"

namespace Engine {

	void Scene::Update(const World& world) {
		for (auto& system : m_systems) {
			system->Update(world);
		}
	}
}