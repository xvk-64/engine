#pragma once

#include "entt/entt.hpp"
#include "Scene.h"

namespace Engine {

	class Scene;

// Holds the current scenes as well as the global scene
	class World {
	public:


		void Update();


		entt::registry registry;

	private:
		std::unique_ptr<Scene> m_currentScene;
	};

}