#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Platform/Window/Window.h"
#include "Platform/Platform.h"

namespace Engine::Core {

	struct EngineConfig {
		Platform::WindowConfig windowConfig;
	};

	class Engine {
	public:
		explicit Engine(const EngineConfig& config);


	private:
		std::unique_ptr<Platform::Platform> platform;
	};

}

#endif //ENGINE_ENGINE_H
