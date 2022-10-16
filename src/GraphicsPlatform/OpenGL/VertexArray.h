#pragma once

#include "Graphics/VertexArray.h"
#include "glad/glad.h"

namespace Engine::OpenGL {

	class VertexArray : public Engine::VertexArray {
	public:
		VertexArray();
		~VertexArray() override;

		void Bind() override {
			glBindVertexArray(m_handle);
		}
		void Unbind() override {
			glBindVertexArray(0);
		}

		void AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) override;

	private:
		uint32_t m_handle = 0;
		uint32_t m_vertexAttributeIndex = 0;
		std::vector<std::unique_ptr<VertexBuffer>> m_vertexBuffers;
	};

}


std::unique_ptr<Engine::VertexArray> Engine::VertexArray::Create() {
	return std::make_unique<Engine::OpenGL::VertexArray>();
}
