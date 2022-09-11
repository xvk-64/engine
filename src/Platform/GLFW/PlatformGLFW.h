//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_PLATFORMGLFW_H
#define ENGINE_PLATFORMGLFW_H

#include "Platform/Platform.h"
#include "Platform/GLFW/Window/WindowGLFW.h"

namespace Engine::Platform::GLFW {

	class PlatformGLFW : public Platform {
	public:
		explicit PlatformGLFW(const WindowConfig& windowConfig) : window(windowConfig) {}

		const Window& GetWindow() override;

	private:
		WindowGLFW window;
	};

}


#endif //ENGINE_PLATFORMGLFW_H
