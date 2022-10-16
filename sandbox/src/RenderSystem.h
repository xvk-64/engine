#pragma once

#include <vector>
#include "ECS/System.h"
#include "Graphics/VertexArray.h"
#include "Graphics/Shader.h"
#include "Core/Application.h"

namespace Sandbox {

class RenderSystem : public Engine::System {
public:
	RenderSystem() {
		auto& modelManager = Engine::Application::Get().GetModelManager();

		m_cube = modelManager.GetStaticMesh("Cube");

		m_shader = Engine::Shader::FromFile("assets/shaders/shader.vert", "assets/shaders/shader.frag");
	}

	void Update(const Engine::World& world) override {
		auto& renderer = Engine::Application::Get().GetRenderer();

		m_shader->Bind();

		renderer.DrawIndexed(m_cube->GetVertexArray());
	}

	std::shared_ptr<Engine::Mesh> m_cube;

	std::unique_ptr<Engine::Shader> m_shader;
};

} // Sandbox
