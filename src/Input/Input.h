#pragma once

#include "Keycode.h"
#include "Mousecode.h"

namespace Engine {

	class Input {
		// TODO: Upgrade to an axis-based system so we don't rely on keyboard/mouse
	public:
		virtual ~Input() = default;


		// Whether the key is down or not
		virtual bool GetKey(Keycode keycode) = 0;

		virtual bool GetMouseButton(Mousecode mousecode) = 0;


		// Get current mouse position
		virtual glm::vec2 GetMousePosition() = 0;

		// Get mouse delta
		virtual glm::vec2 GetMouseDelta() = 0;
	};

}
