#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Engine {

	class Camera {
	public:
		Camera() {
			RecalculateProjection();
		}


		void SetViewportSize(uint32_t width, uint32_t height) {
			m_aspectRatio = (float) width / (float) height;
			RecalculateProjection();
		}

		const glm::mat4& GetProjection() const {
			return m_projection;
		}

		void SetFOV(float FOV) {m_FOV = FOV; RecalculateProjection();}

	private:
		// Recalculate the projection matrix.
		void RecalculateProjection() {
			m_projection = glm::perspective(m_FOV, m_aspectRatio, m_nearDistance, m_farDistance);
		}


		glm::mat4 m_projection = glm::mat4(1.0f);

		// Vertical field of view
		float m_FOV = glm::radians(45.0f);

		// Near clipping plane
		float m_nearDistance = 0.01f;
		// Far clipping plane
		float m_farDistance = 1000.0f;

		float m_aspectRatio = 1.0f;
	};

} // Engine
