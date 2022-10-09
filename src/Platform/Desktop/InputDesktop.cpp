#include "InputDesktop.h"
#include "WindowDesktop.h"
#include "Core/Application.h"

namespace Engine {

	bool InputDesktop::GetKey(Keycode keycode) {
		auto& window = dynamic_cast<WindowDesktop&>(Application::Get().GetWindow());

		return glfwGetKey(window.GetWindowHandle(), keycode) == GLFW_PRESS;
	}

	bool InputDesktop::GetKeyDown(Keycode keycode) {
		return false;
	}

	bool InputDesktop::GetKeyUp(Keycode keycode) {
		return false;
	}
};