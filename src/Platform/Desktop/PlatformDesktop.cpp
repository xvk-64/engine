//
// Created by valen on 11/09/2022.
//

#include "PlatformDesktop.h"

namespace Engine {

	std::unique_ptr<Platform> Platform::Create(const std::string& title, const Platform::PlatformConfig& config) {
		return std::make_unique<PlatformDesktop>(title, config);
	}

	Window& PlatformDesktop::GetCurrentWindow() {
		return m_window;
	}
//
//	Input& PlatformDesktop::GetInput() {
//
//	}

}