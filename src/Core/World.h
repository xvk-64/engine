#pragma once

#include "entt/entt.hpp"
#include "Scene.h"

namespace Engine {

	class Scene;

	// Holds the current scene
	class World {
	public:
		void SwitchScene(std::unique_ptr<Scene> nextScene) {
			m_nextScene = std::move(nextScene);
		}

		void Update();


		entt::registry registry;

	private:
		std::unique_ptr<Scene> m_currentScene;
		std::unique_ptr<Scene> m_nextScene;
	};

}