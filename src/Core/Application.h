#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "Window.h"
#include "Platform.h"

int main();

namespace Engine::Core {

	struct ApplicationConfig {
		WindowConfig windowConfig;
	};

	class Application {
	public:
		explicit Application(const ApplicationConfig& config);
		virtual ~Application();


	private:
		void Run();

		std::unique_ptr<Platform> m_platform;
		bool m_running = true;

		friend int ::main();
	};
}

#endif //ENGINE_APPLICATION_H
