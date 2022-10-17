#pragma once

#include "Core/Scene.h"
#include "ECS/Systems/RenderSystem.h"
#include "ECS/Components.h"

namespace Sandbox {

	class SandboxScene : public Engine::Scene {
	public:
		SandboxScene() {
			RegisterSystem<Engine::RenderSystem>();
		}

		void OnAttach(Engine::World& world) override {
			std::cout << "Attached scene!" << std::endl;


			auto& modelManager = Engine::Application::Get().GetModelManager();

			// Create cube
			auto cubeMesh = modelManager.GetStaticMesh("Cube");
			auto model = std::make_shared<Engine::Model>();
			model->AddMesh(cubeMesh);

			auto cube = world.registry.create();
			world.registry.emplace<Engine::TransformComponent>(cube);
			world.registry.emplace<Engine::ModelComponent>(cube, model);


			// Create camera
			auto camera = world.registry.create();
			auto& transform = world.registry.emplace<Engine::TransformComponent>(camera);
			transform.Translation = glm::vec3(-2, 2, 1);
			transform.Rotation = glm::vec3(glm::radians(-45.0f), glm::radians(-45.0f), 0.0f);
			world.registry.emplace<Engine::CameraComponent>(camera);
		}

		void OnDetach(Engine::World& world) override {

		}
	};

}
