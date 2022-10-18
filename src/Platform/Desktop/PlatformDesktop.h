#pragma once

#include "GLFW/glfw3.h"
#include "Core/Platform.h"
#include "Core/Time.h"
#include "WindowDesktop.h"
#include "InputDesktop.h"

namespace Engine {

class PlatformDesktop : public Platform {
public:
	explicit PlatformDesktop(const std::string& title, const PlatformConfig& config)
		: m_window{title, config.windowConfig},
		  m_input{m_window.GetWindowHandle()} {}


	Window& GetCurrentWindow() override {return m_window;}
	Input& GetInput() override {return m_input;}

	void Update() override;
private:
		WindowDesktop m_window;
		InputDesktop m_input;
	};


	std::unique_ptr<Platform> Platform::Create(const std::string& title, const Platform::PlatformConfig& config) {
		return std::make_unique<PlatformDesktop>(title, config);
	}


	double Time::GetTime() {
		return glfwGetTime();
	}
}