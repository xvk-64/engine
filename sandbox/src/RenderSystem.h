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
		m_va = Engine::VertexArray::Create();

		Engine::BufferLayout bl {
			Engine::BufferDataType::Float3, // Position
			Engine::BufferDataType::Float3, // Colour
		};

		auto vertices = std::array{
			// positions          // colors
			 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // bottom left
			 0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   // top
		};

		uint32_t indices[] {
			0, 1, 2,
		};

		auto buf = Engine::VertexBuffer::Create(bl, vertices);
		m_va->AddVertexBuffer(std::move(buf));
		m_va->SetIndices(indices);

		m_shader = Engine::Shader::FromFile("assets/shaders/shader.vert", "assets/shaders/shader.frag");
	}

	void Update(const Engine::World& world) override {
		auto& renderer = Engine::Application::Get().GetRenderer();

		m_shader->Bind();
		m_va->Bind();
		renderer.DrawIndexed(m_va);

		m_va->Unbind();
	}

	std::unique_ptr<Engine::VertexArray> m_va;

	std::unique_ptr<Engine::Shader> m_shader;
};

} // Sandbox
