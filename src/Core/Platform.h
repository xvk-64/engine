#pragma once

#include <memory>
#include "Window.h"
#include "Input/Input.h"
#include "Utils/Singleton.hpp"

namespace Engine {

	class Platform {
	public:
		struct PlatformConfig {
			WindowConfig windowConfig;
		};

		virtual ~Platform() = default;


		// Defined in implementation-specific platform
		static std::unique_ptr<Platform> Create(const PlatformConfig& config);

		virtual Window& GetCurrentWindow() = 0;
//		virtual Input& GetInput() = 0;
	};
}
