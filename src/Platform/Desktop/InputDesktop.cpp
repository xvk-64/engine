#include "InputDesktop.h"
#include "WindowDesktop.h"
#include "Core/Application.h"

namespace Engine {

	bool InputDesktop::GetKey(Keycode keycode) {
		return glfwGetKey(m_windowHandle, keycode) == GLFW_PRESS;
	}

	bool InputDesktop::GetKeyDown(Keycode keycode) {
		return false;
	}

	bool InputDesktop::GetKeyUp(Keycode keycode) {
		return false;
	}
};