#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Graphics/Camera.h"
#include "Graphics/Model.h"

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
		Camera Camera;
	};


	// Represents a model that can be rendered.
	struct ModelComponent {
		std::shared_ptr<Model> Model;
	};
}