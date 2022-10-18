#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Graphics/Camera.h"
#include "Graphics/Model.h"
#include "Utils/AABB.h"

namespace Engine {
	// Holds the translation, rotation and scale.
	struct TransformComponent {
		glm::vec3 Translation = glm::vec3(0.0f);
		glm::vec3 Rotation = glm::vec3(0.0f);
		glm::vec3 Scale = glm::vec3(1.0f);

		// Get the transform matrix
		glm::mat4 GetTransformMatrix() const {
			glm::mat4 transform = glm::mat4(1.0f);

			transform = glm::translate(transform, Translation);
			transform = transform * glm::mat4(glm::quat(Rotation));
			transform = glm::scale(transform, Scale);

			return transform;
		}
	};


	// Represents a camera in the world.
	struct CameraComponent {
		Camera camera;
	};


	// Freecam
	struct FreeCameraComponent {
		float MoveSpeed = 3.0f;
		float LookSpeed = 0.1f;
		bool InvertY = true;
		bool InvertX = true;
	};


	// Represents a model that can be rendered.
	struct ModelComponent {
		std::shared_ptr<Model> model;
	};


	// Physics
	struct PhysicsComponent {
		// Current velocity
		glm::vec3 velocity = glm::vec3(0.0f);

		// Has the axis collided on this axis?
		glm::bvec3 touching = glm::bvec3(false);

		AABB aabb;

		bool hasGravity = true;
		bool canCollide = true;
	};


	// Movement controlled by a player
	struct PlayerMovementComponent {
		float groundAcceleration = 60.0f;
		float airAcceleration = 8.0f;
		float flyAcceleration = 100.0f;
		float jumpHeight = 1.1f;

		bool isFlying = false;
		bool flyCooldown = false;

		float lookSpeed = 0.1f;
		bool invertY = true;
		bool invertX = true;
	};


	// Shooting cubes
	struct CubeShooterComponent {
		float velocity = 20.0f;
		bool inCooldown = false;
	};
}