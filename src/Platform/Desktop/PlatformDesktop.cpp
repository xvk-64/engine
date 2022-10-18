//
// Created by valen on 11/09/2022.
//

#include "PlatformDesktop.h"

namespace Engine {

	void PlatformDesktop::Update() {
		m_window.Update();
		m_input.Update();
	}

}