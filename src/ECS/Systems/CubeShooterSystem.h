#pragma once

#include "Core/Application.h"

namespace Engine {

	class CubeShooterSystem : public System {
	public:
		void Update(World& world) override {
			if (m_model == nullptr) {
				// Get the model.

				auto& modelManager = world.GetApplication().GetModelManager();

				auto cubeMesh = modelManager.GetStaticMesh("Cube");
				m_model = std::make_shared<Engine::Model>();
				m_model->AddMesh(cubeMesh);
			}


			auto& input = world.GetApplication().GetInput();

			auto view = world.registry.view<TransformComponent, CubeShooterComponent>();
			for (auto entity : view) {
				auto& transformComponent = view.get<TransformComponent>(entity);
				auto& cubeShooterComponent = view.get<CubeShooterComponent>(entity);

				if (input.GetMouseButton(Mousecode::ButtonLeft)) {
					if (!cubeShooterComponent.inCooldown) {
						cubeShooterComponent.inCooldown = true;

						const auto rotation = glm::toMat4(glm::quat(transformComponent.Rotation));
						const auto forward = glm::normalize(glm::vec3(rotation * glm::vec4(0, 0, -1, 0)));

						// Spawn new cube
						auto cubeEntity = world.registry.create();
						auto& cubeTransform = world.registry.emplace<Engine::TransformComponent>(cubeEntity);
						cubeTransform.Translation = transformComponent.Translation + forward * 2.0f;
						world.registry.emplace<Engine::ModelComponent>(cubeEntity, m_model);
						auto& cubePhysics = world.registry.emplace<Engine::PhysicsComponent>(cubeEntity);
						cubePhysics.velocity = forward * cubeShooterComponent.velocity;
					}
				} else
					cubeShooterComponent.inCooldown = false;
			}
		}

	private:
		std::shared_ptr<Model> m_model;
	};

} // Engine
