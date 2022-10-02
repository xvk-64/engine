#include "InputDesktop.h"
#include "WindowDesktop.h"
#include "Core/Engine.h"

namespace Engine {

	bool InputDesktop::GetKey(Keycode keycode) {
		auto& window = dynamic_cast<WindowDesktop&>(Engine::Get().GetWindow());

		return glfwGetKey(window.GetWindowHandle(), keycode) == GLFW_PRESS;
	}

	bool InputDesktop::GetKeyDown(Keycode keycode) {
		return false;
	}

	bool InputDesktop::GetKeyUp(Keycode keycode) {
		return false;
	}
};