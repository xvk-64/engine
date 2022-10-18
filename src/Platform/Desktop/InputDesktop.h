#pragma once

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include "Input/Input.h"

namespace Engine {

	class InputDesktop : public Input {
	public:
		InputDesktop() = delete;
		explicit InputDesktop(GLFWwindow* windowHandle);


		bool GetKey(Keycode keycode) override;

		bool GetMouseButton(Mousecode mousecode) override;

		glm::vec2 GetMousePosition() override {return m_mousePosition;}

		glm::vec2 GetMouseDelta() override {return m_mouseDelta;}

		void Update();


	private:
		GLFWwindow* m_windowHandle;

		glm::vec2 m_mousePosition = glm::vec2(0.0f);
		glm::vec2 m_mouseDelta = glm::vec2(0.0f);
	};

};
