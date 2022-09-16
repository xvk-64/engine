//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_WINDOWGLFW_H
#define ENGINE_WINDOWGLFW_H

#include <GLFW/glfw3.h>
#include <memory>
#include "Core/Window.h"

namespace Engine::Platform::GLFW {

	class WindowGLFW : public Core::Window {
	public:
		explicit WindowGLFW() = default;
		~WindowGLFW();

		void Init(GLFWwindow* windowHandle, const Core::WindowConfig& config);

		void Clear() override;

		void OnUpdate() override;

		void SetVSync(bool enabled) override {
			m_windowData.VSync = enabled;
			glfwSwapInterval(enabled);
		}
		bool GetVSync() override { return m_windowData.VSync; }

	private:
		GLFWwindow* m_windowHandle = nullptr;

		struct WindowData {
			std::string Title;
			Core::WindowConfig::WindowSize Size;
			bool VSync;

		} m_windowData;
	};

}


#endif //ENGINE_WINDOWGLFW_H
