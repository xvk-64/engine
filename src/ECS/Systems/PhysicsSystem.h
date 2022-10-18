#pragma once

#include "ECS/System.h"

namespace Engine {

	class PhysicsSystem : public System {
	public:
		static constexpr float Gravity = 10.0f;
		static constexpr float MovementEpsilon = 0.01f;
		static constexpr float DragCoefficient = 1.0f;
		static constexpr float FrictionCoefficient = 0.8f;

		void Update(World& world) override {
			auto view = world.registry.view<PhysicsComponent, TransformComponent>();

			// Collect all aabbs
			std::vector<AABB*> aabbs;
			for (auto entity : view)
				aabbs.push_back(&view.get<PhysicsComponent>(entity).aabb);


			// Iterate all physics entities
			for (auto entity : view) {
				auto& physicsComponent = view.get<PhysicsComponent>(entity);
				auto& transformComponent = view.get<TransformComponent>(entity);

				// Apply gravity
				if (physicsComponent.hasGravity)
					physicsComponent.velocity -= glm::vec3(0, Gravity, 0) * world.GetDeltaTime();

				// Update AABB center
				physicsComponent.aabb.Center = transformComponent.Translation;


				glm::vec3 targetMoveAmount = physicsComponent.velocity * world.GetDeltaTime();
				glm::vec3 moveAmount = targetMoveAmount;

				if (physicsComponent.canCollide) {

					AABB moved = physicsComponent.aabb;

					// Check all AABBs, each axis individually
					for (int axis = 0; axis < 3; ++axis) {
						float safeMove = targetMoveAmount[axis];

						for (auto* aabb: aabbs) {
							if (aabb->Center == physicsComponent.aabb.Center)
								// Don't check against self.
								continue;


							moved.Center = physicsComponent.aabb.Center;
							moved.Center[axis] += safeMove;

							if (moved.Test(*aabb)) {
								auto depth = moved.CollisionDepth(*aabb)[axis];

								safeMove -= glm::sign(targetMoveAmount[axis]) * (depth + MovementEpsilon);

								if (glm::abs(safeMove) < MovementEpsilon) {
									safeMove = 0.0f;
									break;
								}
							}
						}

						moveAmount[axis] = glm::abs(safeMove) < glm::epsilon<float>() ? 0.0f : safeMove;
					}

					// Zero the axes which did not move fully
					for (int axis = 0; axis < 3; ++axis) {
						bool touching = glm::abs(moveAmount[axis] - targetMoveAmount[axis]) >= glm::epsilon<float>();
						physicsComponent.touching[axis] = touching;
						if (touching)
							physicsComponent.velocity[axis] = 0.0f;
					}
				} // End collision check


				// Update position
				transformComponent.Translation += moveAmount;
				physicsComponent.aabb.Center = transformComponent.Translation;


				// Add drag
				physicsComponent.velocity *= DragCoefficient;

				// If touching ground, apply friction.
				if (physicsComponent.touching.y)
					physicsComponent.velocity *= FrictionCoefficient;
			}
		}
	};

} // Engine
