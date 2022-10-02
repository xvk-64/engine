#include "Core/EntryPoint.h"

class Sandbox : public Engine::Game {
public:
	Sandbox() {
		Engine::Engine::Get().GetWindow().windowCloseEvent.AddHandler(handleWindowClose);
	}

private:
	void OnWindowClose() {
		OnQuit.Invoke();
	}
	Engine::EventHandler<> handleWindowClose{[this](){this->OnWindowClose();}};
};

std::unique_ptr<Engine::Game> Engine::Engine::CreateGame() {
	return std::make_unique<Sandbox>();
}