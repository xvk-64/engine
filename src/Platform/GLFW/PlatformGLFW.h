//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_PLATFORMGLFW_H
#define ENGINE_PLATFORMGLFW_H

#include "Core/Platform.h"
#include "Window/WindowGLFW.h"

namespace Engine::Platform::GLFW {

class PlatformGLFW : public Core::Platform {
	public:
		explicit PlatformGLFW(const Core::WindowConfig& windowConfig);

		Core::Window& GetWindow() override;

	private:
		WindowGLFW m_window;
	};

}


#endif //ENGINE_PLATFORMGLFW_H
