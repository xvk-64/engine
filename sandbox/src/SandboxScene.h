#pragma once

#include "Core/Scene.h"
#include "RenderSystem.h"

namespace Sandbox {

	class SandboxScene : public Engine::Scene {
	public:
		SandboxScene() {
			RegisterSystem<RenderSystem>();
		}

		void OnAttach(const Engine::World& world) override {
			std::cout << "Attached scene!" << std::endl;
		}

		void OnDetach(const Engine::World& world) override {

		}
	};

}
