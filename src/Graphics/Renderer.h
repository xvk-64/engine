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

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;


		static std::unique_ptr<Renderer> Create();
	};

}