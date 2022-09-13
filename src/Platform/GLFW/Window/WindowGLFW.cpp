//
// Created by valen on 11/09/2022.
//

#include "WindowGLFW.h"

namespace Engine::Platform::GLFW {

	WindowGLFW::WindowGLFW(const Core::WindowConfig& config) {
		glfwInit();
		// Set GLFW version 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_windowHandle = glfwCreateWindow(config.Size.Width, config.Size.Height, config.Title.c_str(), nullptr, nullptr);

		if (m_windowHandle == nullptr) {
			// Failed to create window!

			glfwTerminate();

			throw std::runtime_error("Couldn't create GLFW window.");
		}

		glfwMakeContextCurrent(m_windowHandle);
		glfwSetWindowUserPointer(m_windowHandle, &m_windowData);
	}

	void WindowGLFW::Clear() {

	}

	void WindowGLFW::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_windowHandle);
	}

	WindowGLFW::~WindowGLFW() {
		glfwDestroyWindow(m_windowHandle);
	}
}
