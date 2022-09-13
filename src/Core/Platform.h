//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_PLATFORM_H
#define ENGINE_PLATFORM_H

#include <memory>
#include "Window.h"

namespace Engine::Core {

	class Platform {
	public:
		virtual Window& GetWindow() = 0;

		virtual ~Platform() = default;

		void OnUpdate();


		static std::unique_ptr<Platform> Create(const WindowConfig& windowConfig);
	};

}


#endif //ENGINE_PLATFORM_H
