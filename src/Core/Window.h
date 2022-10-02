#pragma once

#include <string>
#include "glm/glm.hpp"
#include "Utils/Event.h"

namespace Engine {

	struct WindowConfig {
		struct WindowSize {
			int width;
			int height;
		};

		std::string title;
		WindowSize size{1280, 720};
	};

	class Window {
	public:
		virtual void Clear() = 0;
		// Per frame update
		virtual void Update() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool GetVSync() = 0;

		Event<WindowConfig::WindowSize> windowResizeEvent;
		Event<> windowCloseEvent;
	};

}
