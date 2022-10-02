#pragma once

#include <iostream>
#include <memory>
#include "Game.h"
#include "Engine.h"

int main() {
	Engine::Engine engine;
	{
		auto game = Engine::Engine::CreateGame();

		engine.Run(*game);
	} // Ensure engine outlives game
	return 0;
}