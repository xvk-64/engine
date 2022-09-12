#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "Platform/Window/Window.h"
#include "Platform/Platform.h"

int main();

namespace Engine::Core {

	struct ApplicationConfig {
		Platform::WindowConfig windowConfig;
	};

	class Application {
	public:
		explicit Application(const ApplicationConfig& config);
		virtual ~Application();


	private:
		void Run();

		std::unique_ptr<Platform::Platform> m_platform;

		friend int ::main();
	};
}

#endif //ENGINE_APPLICATION_H
