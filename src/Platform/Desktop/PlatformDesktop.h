//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_PLATFORMDESKTOP_H
#define ENGINE_PLATFORMDESKTOP_H

#include "Core/Platform.h"
#include "WindowGLFW.h"
#include "GLFW/glfw3.h"

namespace Engine::Platform {

class PlatformDesktop : public Core::Platform {
	public:
		explicit PlatformDesktop(const Core::WindowConfig& windowConfig);

		Core::Window& GetWindow() override;

	private:
		WindowGLFW m_window;
	};

}


#endif //ENGINE_PLATFORMDESKTOP_H
