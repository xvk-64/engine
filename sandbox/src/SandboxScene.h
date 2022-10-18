#pragma once

#include "Core/Scene.h"
#include "ECS/Systems/RenderSystem.h"
#include "ECS/Components.h"
#include "ECS/Systems/FreeCameraSystem.h"
#include "ECS/Systems/PhysicsSystem.h"
#include "ECS/Systems/PlayerMovementSystem.h"
#include "ECS/Systems/CubeShooterSystem.h"

namespace Sandbox {

	class SandboxScene : public Engine::Scene {
	public:
		SandboxScene() {
			RegisterSystem<Engine::RenderSystem>();
			RegisterSystem<Engine::FreeCameraSystem>();
			RegisterSystem<Engine::PhysicsSystem>();
			RegisterSystem<Engine::PlayerMovementSystem>();
			RegisterSystem<Engine::CubeShooterSystem>();
		}

		void OnAttach(Engine::World& world) override {
			std::cout << "Attached scene!" << std::endl;


			auto& modelManager = world.GetApplication().GetModelManager();

			// Get cube model
			auto cubeMesh = modelManager.GetStaticMesh("Cube");
			auto model = std::make_shared<Engine::Model>();
			model->AddMesh(cubeMesh);


			// Create floor
			auto floorEntity = world.registry.create();

			auto& floorTransform = world.registry.emplace<Engine::TransformComponent>(floorEntity);
			floorTransform.Scale = glm::vec3(30.0f, 1.0f, 30.0f);

			world.registry.emplace<Engine::ModelComponent>(floorEntity, model);

			auto& floorPhysics = world.registry.emplace<Engine::PhysicsComponent>(floorEntity);
			floorPhysics.hasGravity = false;
			floorPhysics.aabb.HalfWidths = floorTransform.Scale / 2.0f;


			// Create cube
			for (int i = 0; i < 1; ++i) {
				auto cube2 = world.registry.create();
				auto& tr = world.registry.emplace<Engine::TransformComponent>(cube2);
				tr.Translation = glm::vec3(0.0f, 2.0f + 2 * i, 0.0f);
				world.registry.emplace<Engine::ModelComponent>(cube2, model);
				world.registry.emplace<Engine::PhysicsComponent>(cube2);
			}


//			// Create freecam
//			auto camera = world.registry.create();
//			auto& transform = world.registry.emplace<Engine::TransformComponent>(camera);
//			transform.Translation = glm::vec3(-2, 2, 1);
//			transform.Rotation = glm::vec3(glm::radians(-45.0f), glm::radians(-45.0f), 0.0f);
//			world.registry.emplace<Engine::CameraComponent>(camera);
//			world.registry.emplace<Engine::FreeCameraComponent>(camera);

			// Create player
			auto playerEntity = world.registry.create();

			auto& playerTransform = world.registry.emplace<Engine::TransformComponent>(playerEntity);
			playerTransform.Translation = glm::vec3(0.0f, 5.0f, 5.0f);

			auto& cameraComponent = world.registry.emplace<Engine::CameraComponent>(playerEntity);
			cameraComponent.camera.SetFOV(glm::radians(60.0f));

			auto& playerPhysics = world.registry.emplace<Engine::PhysicsComponent>(playerEntity);
			playerPhysics.aabb.HalfWidths = glm::vec3(0.2f, 1.25f, 0.2f);

			world.registry.emplace<Engine::PlayerMovementComponent>(playerEntity);

			world.registry.emplace<Engine::CubeShooterComponent>(playerEntity);

		}

		void OnDetach(Engine::World& world) override {

		}
	};

}
