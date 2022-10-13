#pragma once


#include "World.h"
#include "ECS/System.h"

namespace Engine {

	class World;
	class System;

	class Scene {
	public:
		Scene() = delete;
		explicit Scene(World& world) : m_world(world) {}

		virtual ~Scene() = default;


		void Update();

	protected:
		World& m_world;

		template <typename T>
		void RegisterSystem() {
			m_systems.emplace_back(std::make_unique<T>(m_world));
		}

	private:
		std::vector<std::unique_ptr<System>> m_systems;
	};

}