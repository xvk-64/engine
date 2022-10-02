#pragma once

#include <concepts>
#include <memory>
#include "Game.h"
#include "Platform.h"

int main();

namespace Engine {

	// Manages initialisation and cleanup of essential engine subsystems.
	class Engine {
	public:
		Engine();


		static Engine& Get() {return *s_instance;}


		Window& GetWindow() {return m_platform->GetCurrentWindow();}

	private:
		friend int ::main();
		// Run the engine
		void Run(Game& game);

		// Defined in client
		static std::unique_ptr<Game> CreateGame();

		std::unique_ptr<Platform> m_platform;

		static Engine* s_instance;
	};

} // Engine
