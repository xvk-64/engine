//
// Created by valen on 11/09/2022.
//

#ifndef ENGINE_ENTRYPOINT_H
#define ENGINE_ENTRYPOINT_H

#include <iostream>
#include "Application.h"

namespace Engine::Core {
// Defined in client.
	extern std::unique_ptr<Engine::Core::Application> CreateApplication();
}

int main() {
	auto application = Engine::Core::CreateApplication();

	application->Run();

	return 0;
}

#endif //ENGINE_ENTRYPOINT_H
