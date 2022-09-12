//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_PLATFORM_H
#define ENGINE_PLATFORM_H

#include <memory>
#include "Platform/Window/Window.h"

namespace Engine::Platform {

	class Platform {
	public:
		virtual const Window& GetWindow() = 0;

		virtual ~Platform() = default;

		static std::unique_ptr<Platform> Create(const WindowConfig& windowConfig);
	};

}


#endif //ENGINE_PLATFORM_H
