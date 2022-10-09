#pragma once

#include "Core/Platform.h"
#include "WindowDesktop.h"
#include "GLFW/glfw3.h"

namespace Engine {

class PlatformDesktop : public Platform {
public:
	explicit PlatformDesktop(const std::string& title, const PlatformConfig& config) : m_window(title, config.windowConfig) {}

	Window& GetCurrentWindow() override;

//	Input& GetInput() override;

private:
		WindowDesktop m_window;


	};

}
