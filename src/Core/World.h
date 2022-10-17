#pragma once

#include "entt/entt.hpp"
#include "Scene.h"
#include "ECS/Components.h"

namespace Engine {

	class Scene;

	// Holds the current scene
	class World {
	public:
		World();

		// Copy and move
		World(World& other) = delete;
		World& operator==(World& other) = delete;
		World(World&& other) = delete;
		World& operator==(World&& other) = delete;

		~World() = default;


		void SwitchScene(std::unique_ptr<Scene> nextScene) {
			m_nextScene = std::move(nextScene);
		}

		void Update();

		void OnViewportResize(uint32_t width, uint32_t height);


		entt::registry registry;

	private:
		void OnCameraAdded(entt::registry& registry, entt::entity entity);


		std::unique_ptr<Scene> m_currentScene;
		std::unique_ptr<Scene> m_nextScene;

		uint32_t m_viewportWidth = 0;
		uint32_t m_viewportHeight = 0;
	};

}