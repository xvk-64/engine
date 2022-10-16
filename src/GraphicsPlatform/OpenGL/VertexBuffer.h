#pragma once

#include <utility>

#include "Graphics/VertexBuffer.h"
#include "glad/glad.h"

namespace Engine::OpenGL {

	class VertexBuffer : public Engine::VertexBuffer {
	public:
		VertexBuffer() = delete;
		VertexBuffer(Engine::BufferLayout layout, std::span<float> data);
		~VertexBuffer() override {
			glDeleteBuffers(1, &m_handle);
		};


		void Bind() override;
		void Unbind() override;

		void SetData(std::span<float> data) override;
		const BufferLayout& GetLayout() override {return m_layout;}


	private:
		BufferLayout m_layout;
		uint32_t m_handle = 0;
	};
} // Engine

std::unique_ptr<Engine::VertexBuffer> Engine::VertexBuffer::Create(const Engine::BufferLayout& layout, std::span<float> data) {
	return std::make_unique<OpenGL::VertexBuffer>(layout, data);
}