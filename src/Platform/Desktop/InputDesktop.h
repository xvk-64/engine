#pragma once

#include <GLFW/glfw3.h>
#include "Input/Input.h"

namespace Engine {

	class InputDesktop : public Input {
	public:
		InputDesktop() = delete;
		explicit InputDesktop(GLFWwindow* windowHandle) : m_windowHandle(windowHandle) {}


		bool GetKey(Keycode keycode) override;
		bool GetKeyDown(Keycode keycode) override;
		bool GetKeyUp(Keycode keycode) override;


	private:
		GLFWwindow* m_windowHandle;
	};

};
