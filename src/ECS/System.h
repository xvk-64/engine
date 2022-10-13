#pragma once

#include "Core/World.h"

namespace Engine {

	class World;

	class System {
	public:
		System() = delete;
		explicit System(World& world) : m_world(world) {}

		virtual void Update() = 0;

	protected:
		World& m_world;
	};

} // Engine
