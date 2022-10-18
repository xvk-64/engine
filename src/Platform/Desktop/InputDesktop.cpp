#include "InputDesktop.h"
#include "WindowDesktop.h"
#include "Core/Application.h"

namespace Engine {
	InputDesktop::InputDesktop(GLFWwindow* windowHandle) : m_windowHandle(windowHandle) {
		double x, y;
		glfwGetCursorPos(m_windowHandle, &x, &y);
		glm::vec2 pos{x, y};

		m_mousePosition = pos;
	}


	bool InputDesktop::GetKey(Keycode keycode) {
		return glfwGetKey(m_windowHandle, keycode) == GLFW_PRESS;
	}

	bool InputDesktop::GetKeyDown(Keycode keycode) {
		return false;
	}

	bool InputDesktop::GetKeyUp(Keycode keycode) {
		return false;
	}

	void InputDesktop::Update() {
		double x, y;
		glfwGetCursorPos(m_windowHandle, &x, &y);

		glm::vec2 pos{x, y};

		m_mouseDelta = pos - m_mousePosition;
		m_mousePosition = pos;
	}
};