//
// Created by valen on 11/09/2022.
//

#include "WindowGLFW.h"

namespace Engine::Platform::GLFW {

	WindowGLFW::WindowGLFW(const WindowConfig& config) {
		glfwInit();
		// Set GLFW version 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		windowHandle = glfwCreateWindow(config.windowSize.x, config.windowSize.y, config.windowTitle.c_str(), nullptr, nullptr);

		if (windowHandle == nullptr) {
			// Failed to create window!

			glfwTerminate();

			throw std::runtime_error("Couldn't create GLFW window.");
		}

		glfwMakeContextCurrent(windowHandle);
	}

	void WindowGLFW::Clear() {

	}
}
