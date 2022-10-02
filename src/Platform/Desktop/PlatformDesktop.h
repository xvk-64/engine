#pragma once

#include "Core/Platform.h"
#include "WindowDesktop.h"
#include "GLFW/glfw3.h"

namespace Engine {

class PlatformDesktop : public Platform {
public:
	explicit PlatformDesktop(const PlatformConfig& config) : m_window(config.windowConfig) {}

	Window& GetCurrentWindow() override;

//	Input& GetInput() override;

private:
		WindowDesktop m_window;


	};

}
