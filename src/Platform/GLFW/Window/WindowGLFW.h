//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_WINDOWGLFW_H
#define ENGINE_WINDOWGLFW_H

#include <GLFW/glfw3.h>
#include <memory>
#include "Platform/Window/Window.h"

namespace Engine::Platform::GLFW {

	class WindowGLFW : public Window {
	public:
		explicit WindowGLFW(const WindowConfig& config);

	private:
		GLFWwindow* windowHandle = nullptr;
	};

}


#endif //ENGINE_WINDOWGLFW_H
