//
// Created by valen on 11/09/2022.
//

#include <iostream>
#include "WindowGLFW.h"

namespace Engine::Platform::GLFW {

	void WindowGLFW::Init(GLFWwindow* windowHandle, const Core::WindowConfig& config) {
		m_windowHandle = windowHandle;
		m_windowData.Title = config.Title;
		m_windowData.Size = config.Size;

		glfwMakeContextCurrent(windowHandle);
		WindowGLFW::SetVSync(true);

		// Set callbacks
		glfwSetWindowSizeCallback(m_windowHandle, [](GLFWwindow* window, int width, int height) {
			static_cast<WindowGLFW*>(glfwGetWindowUserPointer(window))->WindowResizeEvent.Invoke({.Width=width, .Height=height});
		});

		glfwSetWindowCloseCallback(m_windowHandle, [](GLFWwindow* window) {
			static_cast<WindowGLFW*>(glfwGetWindowUserPointer(window))->WindowCloseEvent.Invoke();
		});
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
