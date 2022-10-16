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

		auto buf = Engine::VertexBuffer::Create(bl, vertices);
		m_va->AddVertexBuffer(std::move(buf));

		m_shader = Engine::Shader::Create("#version 330 core\n"
		                                  "layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0\n"
		                                  "layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n"
		                                  "  \n"
		                                  "out vec3 ourColor; // output a color to the fragment shader\n"
		                                  "\n"
		                                  "void main()\n"
		                                  "{\n"
		                                  "    gl_Position = vec4(aPos, 1.0);\n"
		                                  "    ourColor = aColor; // set ourColor to the input color we got from the vertex data\n"
		                                  "}",

										  "#version 330 core\n"
		                                  "out vec4 FragColor;  \n"
		                                  "in vec3 ourColor;\n"
		                                  "  \n"
		                                  "void main()\n"
		                                  "{\n"
		                                  "    FragColor = vec4(ourColor, 1.0);\n"
		                                  "}");
	}

	void Update(const Engine::World& world) override {
		auto& renderer = Engine::Application::Get().GetRenderer();

		m_shader->Bind();
		m_va->Bind();
		renderer.DrawArray(m_va);

		m_va->Unbind();
	}

	std::unique_ptr<Engine::VertexArray> m_va;

	std::unique_ptr<Engine::Shader> m_shader;
};

} // Sandbox
