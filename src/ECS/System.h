#pragma once

#include "Core/World.h"

namespace Engine {

	class World;

	// Base class for a System which operates on entities.
	class System {
	public:
		virtual ~System() = default;

		virtual void Update(const World& world) = 0;
	};

} // Engine
