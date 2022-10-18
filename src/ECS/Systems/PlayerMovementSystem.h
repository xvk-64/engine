#pragma once

#include "Core/Application.h"
#include "PhysicsSystem.h"

namespace Engine {

	class PlayerMovementSystem : public System {
	public:
		void Update(World& world) override {
			auto& input = world.GetApplication().GetInput();

			auto view = world.registry.view<PlayerMovementComponent, TransformComponent, PhysicsComponent, CameraComponent>();
			for (auto entity : view) {
				auto& playerMovementComponent = view.get<PlayerMovementComponent>(entity);
				auto& physicsComponent = view.get<PhysicsComponent>(entity);
				auto& transformComponent = view.get<TransformComponent>(entity);
				auto& cameraComponent = view.get<CameraComponent>(entity);

				auto forward = -glm::vec3(glm::sin(transformComponent.Rotation.y), 0.0f, glm::cos(transformComponent.Rotation.y));
				auto right = glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f));

				auto acceleration = playerMovementComponent.isFlying
						? playerMovementComponent.flyAcceleration
						: (physicsComponent.touching.y
							? playerMovementComponent.groundAcceleration
							: playerMovementComponent.airAcceleration);

				auto direction = glm::vec3(0.0f);

				if (input.GetKey(Keycode::W))
					direction += forward;
				if (input.GetKey(Keycode::S))
					direction -= forward;
				if (input.GetKey(Keycode::A))
					direction -= right;
				if (input.GetKey(Keycode::D))
					direction += right;

				if (playerMovementComponent.isFlying) {

				} else {
					if (input.GetKey(Keycode::Space) && physicsComponent.touching.y)
						// Jump if on the ground
						physicsComponent.velocity.y += glm::sqrt(2 * PhysicsSystem::Gravity * playerMovementComponent.jumpHeight);
				}

				// Apply velocity
				physicsComponent.velocity += direction * acceleration * world.GetDeltaTime();


				// Mouse looking
				transformComponent.Rotation += glm::radians(glm::vec3(
						input.GetMouseDelta().y * (playerMovementComponent.invertY ? -1.0f : 1.0f),
						input.GetMouseDelta().x * (playerMovementComponent.invertX ? -1.0f : 1.0f),
						0)) * playerMovementComponent.lookSpeed;

				transformComponent.Rotation.x = glm::clamp(transformComponent.Rotation.x, glm::radians(-89.0f), glm::radians(89.0f));
			}
		}
	};

} // Engine
