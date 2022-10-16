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

		void SetIndices(std::span<uint32_t> indices) override;

		size_t GetIndexCount() override {return m_indexCount;}

	private:
		uint32_t m_handle = 0;

		uint32_t m_indexHandle = 0;
		size_t m_indexCount = 0;

		uint32_t m_vertexAttributeIndex = 0;

		std::vector<std::unique_ptr<VertexBuffer>> m_vertexBuffers;
	};

}


std::unique_ptr<Engine::VertexArray> Engine::VertexArray::Create() {
	return std::make_unique<Engine::OpenGL::VertexArray>();
}
