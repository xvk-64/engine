//
// Created by valen on 10/09/2022.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <string>
#include "glm/glm.hpp"

namespace Engine::Platform {

	struct WindowConfig {
		std::string windowTitle;
		glm::ivec2 windowSize;
	};

	class Window {
		virtual void Clear() = 0;
	};

}

#endif //ENGINE_WINDOW_H
