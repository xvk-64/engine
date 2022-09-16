//
// Created by valen on 11/09/2022.
//

#include "PlatformDesktop.h"

namespace Engine::Platform::GLFW {

	Core::Window& PlatformDesktop::GetWindow() {
		return m_window;
	}

	PlatformDesktop::PlatformDesktop(const Core::WindowConfig& windowConfig) {
		glfwInit();
		// Set Desktop version 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		auto windowHandle = glfwCreateWindow(windowConfig.Size.Width, windowConfig.Size.Height, windowConfig.Title.c_str(), nullptr, nullptr);

		if (windowHandle == nullptr) {
			// Failed to create window!

			glfwTerminate();

			throw std::runtime_error("Couldn't create Desktop window.");
		}

		glfwSetWindowUserPointer(windowHandle, &m_window);
		m_window.Init(windowHandle, windowConfig);
	}

}