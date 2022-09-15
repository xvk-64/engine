//
// Created by valen on 10/09/2022.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <string>
#include "glm/glm.hpp"
#include "Event.h"

namespace Engine::Core {

	struct WindowConfig {
		std::string Title;

		struct WindowSize {
			int Width = 1280;
			int Height = 720;
		} Size;
	};

	class Window {
	public:
		virtual void Clear() = 0;
		virtual void OnUpdate() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool GetVSync() = 0;

		Event<WindowConfig::WindowSize> WindowResizeEvent;
		Event<> WindowCloseEvent;
	};

}

#endif //ENGINE_WINDOW_H
