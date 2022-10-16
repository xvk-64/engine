#pragma once

#include "Graphics/Renderer.h"

namespace Engine::OpenGL {

	class Renderer : public Engine::Renderer {
	public:
		Renderer();

		void SetClearColour(const glm::vec4& colour) override;
		void Clear() override;

		void DrawArray(const std::unique_ptr<VertexArray>& vertexArray) override;
	};

}

std::unique_ptr<Engine::Renderer> Engine::Renderer::Create() {
	return std::make_unique<Engine::OpenGL::Renderer>();
}