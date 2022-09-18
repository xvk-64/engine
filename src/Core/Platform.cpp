#include "Platform.h"
#include "Platform/Desktop/PlatformDesktop.h"

namespace Engine::Core {
	std::unique_ptr<Platform> Platform::Create(const WindowConfig& windowConfig) {
		// TODO: Make this create the correct platform class for each platform
		return std::make_unique<Engine::Platform::PlatformDesktop>(windowConfig);
	}

	void Platform::OnUpdate() {
		GetWindow().OnUpdate();
	}
}