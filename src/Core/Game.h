#pragma once

#include "Utils/Event.h"

namespace Engine {

	class Game {
	public:
		Game() = delete;

		virtual ~Game() = default;

		virtual void Update() = 0;

		virtual bool ShouldQuit() = 0;
	};

} // Engine
