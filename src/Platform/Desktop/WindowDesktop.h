#pragma once

#include <GLFW/glfw3.h>
#include <memory>
#include "Core/Window.h"

namespace Engine {

	class WindowDesktop : public Window {
	public:
		WindowDesktop(const WindowConfig& config);

		// Copy and move
		WindowDesktop(WindowDesktop& other) = delete;
		WindowDesktop& operator=(WindowDesktop& other) = delete;
		WindowDesktop(WindowDesktop&& other) = delete;
		WindowDesktop& operator=(WindowDesktop&& other) = delete;

		~WindowDesktop();


		void Clear() override;

		void Update() override;

		void SetVSync(bool enabled) override {
			m_windowData.VSync = enabled;
			glfwSwapInterval(enabled);
		}
		bool GetVSync() override { return m_windowData.VSync; }

		GLFWwindow* GetWindowHandle() {return m_windowHandle;}

	private:
		GLFWwindow* m_windowHandle = nullptr;

		struct WindowData {
			std::string Title;
			WindowConfig::WindowSize Size;
			bool VSync;

		};
		WindowData m_windowData;
	};

}