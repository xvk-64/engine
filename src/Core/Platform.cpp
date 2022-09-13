#include "Platform.h"
#include "Platform/GLFW/PlatformGLFW.h"

namespace Engine::Core {
	std::unique_ptr<Platform> Platform::Create(const WindowConfig& windowConfig) {
		return std::make_unique<Engine::Platform::GLFW::PlatformGLFW>(windowConfig);
	}

	void Platform::OnUpdate() {
		GetWindow().OnUpdate();
	}
}