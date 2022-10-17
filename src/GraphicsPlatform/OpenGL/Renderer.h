#pragma once

#include "Graphics/Renderer.h"

namespace Engine::OpenGL {

	class Renderer : public Engine::Renderer {
	public:
		Renderer();

		void SetClearColour(const glm::vec4& colour) override;
		void Clear() override;

		void DrawIndexed(const VertexArray& vertexArray) override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
	};

}

std::unique_ptr<Engine::Renderer> Engine::Renderer::Create() {
	return std::make_unique<Engine::OpenGL::Renderer>();
}