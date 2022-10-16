#pragma once

#include <glm/glm.hpp>
#include <memory>
#include "VertexArray.h"

namespace Engine {

	class Renderer {
	public:
		virtual ~Renderer() = default;


		virtual void SetClearColour(const glm::vec4& colour) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const VertexArray& vertexArray) = 0;


		static std::unique_ptr<Renderer> Create();
	};

}