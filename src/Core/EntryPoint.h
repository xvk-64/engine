#pragma once

#include <iostream>
#include <memory>
#include "Application.h"

int main() {
	auto application = Engine::Application::CreateApplication();

	application->Run();

	return 0;
}