//
// Created by valen on 11/09/2022.
//

#include "PlatformDesktop.h"

namespace Engine {

	std::unique_ptr<Platform> Platform::Create(const Platform::PlatformConfig& config) {
		return std::make_unique<PlatformDesktop>(config);
	}

	Window& PlatformDesktop::GetCurrentWindow() {
		return m_window;
	}
//
//	Input& PlatformDesktop::GetInput() {
//
//	}

}