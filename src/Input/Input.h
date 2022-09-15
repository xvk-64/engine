#pragma once

#include "Keycode.h"

namespace Engine::Input {

	class Input {
	public:
		// Whether the key is down or not
		virtual bool GetKey(Keycode keycode);

		// Whether the key was pressed this update
		virtual bool GetKeyDown(Keycode keycode);

		// Whether the key was released this update.
		bool GetKeyUp(Keycode keycode);
	};

}
