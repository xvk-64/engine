//
// Created by valen on 10/09/2022.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <string>
#include "glm/glm.hpp"

namespace Engine::Core {

	struct WindowConfig {
		std::string Title;

		struct WindowSize {
			unsigned int Width = 1280;
			unsigned int Height = 720;
		} Size;
	};

	class Window {
	public:
		virtual void Clear() = 0;
		virtual void OnUpdate() = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool GetVSync() = 0;
	};

}

#endif //ENGINE_WINDOW_H
