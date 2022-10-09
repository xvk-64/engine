#include <iostream>
#include "WindowDesktop.h"

namespace Engine {

	WindowDesktop::WindowDesktop(const std::string& title, const WindowConfig& config) {
		glfwInit();

		// Set OpenGL version 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_windowHandle = glfwCreateWindow(config.size.width, config.size.height, title.c_str(), nullptr, nullptr);

		if (m_windowHandle == nullptr) {
			// Failed to create window!

			glfwTerminate();

			throw std::runtime_error("Couldn't create Desktop window.");
		}

		glfwMakeContextCurrent(m_windowHandle);

		glfwSetWindowUserPointer(m_windowHandle, this);

		m_windowData.Title = title;
		m_windowData.Size = config.size;

		WindowDesktop::SetVSync(true);

		// Set callbacks
		glfwSetWindowSizeCallback(m_windowHandle, [](GLFWwindow* window, int width, int height) {
			auto& windowGLFW = *static_cast<WindowDesktop*>(glfwGetWindowUserPointer(window));

			windowGLFW.m_windowData.Size = {.width=width, .height = height};

			windowGLFW.windowResizeEvent.Invoke(windowGLFW.m_windowData.Size);
		});

		glfwSetWindowCloseCallback(m_windowHandle, [](GLFWwindow* window) {
			auto& windowGLFW = *static_cast<WindowDesktop*>(glfwGetWindowUserPointer(window));

			windowGLFW.windowCloseEvent.Invoke();
		});
	}

	void WindowDesktop::Clear() {

	}

	void WindowDesktop::Update() {
		glfwPollEvents();
		glfwSwapBuffers(m_windowHandle);
	}

	WindowDesktop::~WindowDesktop() {
		glfwDestroyWindow(m_windowHandle);
		glfwTerminate();
	}
}
