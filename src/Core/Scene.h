#pragma once


#include "World.h"
#include "ECS/System.h"

namespace Engine {

	class World;

	class Scene {
	public:
		virtual ~Scene() = default;


		// Called when the scene is attached to a World.
		virtual void OnAttach(World& world) = 0;
		// Called when the scene is detached from a World.
		virtual void OnDetach(World& world) = 0;

		// Called every frame
		void Update(World& world);

	protected:
		// Register a new system to be updated in this Scene
		template <typename T> requires std::derived_from<T, System>
		void RegisterSystem() {
			m_systems.emplace_back(std::make_unique<T>());
		}

	private:
		std::vector<std::unique_ptr<System>> m_systems;
	};

}