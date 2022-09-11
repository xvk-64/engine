//
// Created by valen on 10/09/2022.
//

#include "Engine.h"
#include "Platform/GLFW/PlatformGLFW.h"

namespace Engine::Core {

	Engine::Engine(const EngineConfig& config) {
		m_platform = Platform::Platform::Create();
	}

}
