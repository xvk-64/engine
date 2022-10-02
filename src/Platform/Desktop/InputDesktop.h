#pragma once

#include "Input/Input.h"

namespace Engine {

	class InputDesktop : Input {
		bool GetKey(Keycode keycode) override;

		bool GetKeyDown(Keycode keycode) override;

		bool GetKeyUp(Keycode keycode) override;
	};

};
