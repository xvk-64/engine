#pragma once

#include "Keycode.h"

namespace Engine {

	class Input {
		// TODO: Upgrade to an axis-based system so we don't rely on keyboard/mouse
	public:
		virtual ~Input() = default;


		// Whether the key is down or not
		virtual bool GetKey(Keycode keycode) = 0;

		// Whether the key was pressed this update
		virtual bool GetKeyDown(Keycode keycode) = 0;

		// Whether the key was released this update.
		virtual bool GetKeyUp(Keycode keycode) = 0;
	};

}
