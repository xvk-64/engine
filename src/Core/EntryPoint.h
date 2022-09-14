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
void printstr(int num) {
	std::cout << num << std::endl;
}
void printstr1(int num) {
	std::cout << num << std::endl;
}
int main() {
	auto application = Engine::Core::CreateApplication();

	Engine::Core::Event<int> evnt;

	auto listener = evnt.AddListener(printstr);
	auto li = evnt.AddListener(printstr1);

	evnt.Invoke(8);

	application->Run();

	return 0;
}

#endif //ENGINE_ENTRYPOINT_H
