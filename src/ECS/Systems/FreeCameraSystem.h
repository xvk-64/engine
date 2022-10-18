#pragma once

#include "Core/Application.h"

namespace Engine {

	class FreeCameraSystem : public System {
	public:
		void Update(World& world) override {
			auto& input = world.GetApplication().GetInput();

			auto view = world.registry.view<TransformComponent, CameraComponent, FreeCameraComponent>();
			for (auto entity : view) {
				auto& transform = view.get<TransformComponent>(entity);
				auto& camera = view.get<CameraComponent>(entity);
				auto& freeCam = view.get<FreeCameraComponent>(entity);

				// Get forward vector.
				const auto rotation = glm::toMat4(glm::quat(transform.Rotation));
				const auto forward = glm::normalize(glm::vec3(rotation * glm::vec4(0, 0, -1, 0)));

				// Get right and up vectors.
				const auto right = glm::cross(forward, glm::vec3(0, 1, 0));
				const auto up = glm::cross(right, forward);

				// Do movement
				if (input.GetKey(Keycode::W))
					transform.Translation += freeCam.MoveSpeed * world.GetDeltaTime() * forward;
				if (input.GetKey(Keycode::S))
					transform.Translation -= freeCam.MoveSpeed * world.GetDeltaTime() * forward;
				if (input.GetKey(Keycode::A))
					transform.Translation -= freeCam.MoveSpeed * world.GetDeltaTime() * right;
				if (input.GetKey(Keycode::D))
					transform.Translation += freeCam.MoveSpeed * world.GetDeltaTime() * right;
				if (input.GetKey(Keycode::Space))
					transform.Translation += freeCam.MoveSpeed * world.GetDeltaTime() * up;
				if (input.GetKey(Keycode::LeftControl))
					transform.Translation -= freeCam.MoveSpeed * world.GetDeltaTime() * up;

				// Mouse looking
				transform.Rotation += glm::radians(glm::vec3(
						input.GetMouseDelta().y * (freeCam.InvertY ? -1.0f : 1.0f),
						input.GetMouseDelta().x * (freeCam.InvertX ? -1.0f : 1.0f),
						0)) * freeCam.LookSpeed;

				transform.Rotation.x = glm::clamp(transform.Rotation.x, glm::radians(-89.0f), glm::radians(89.0f));
			}
		}
	};

} // Engine
