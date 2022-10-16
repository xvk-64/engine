#include "VertexBuffer.h"
#include "Graphics/VertexBuffer.h"


namespace Engine::OpenGL {

	VertexBuffer::VertexBuffer(Engine::BufferLayout layout, std::span<float> data) : m_layout(std::move(layout)) {
		glGenBuffers(1, &m_handle);
		glBindBuffer(GL_ARRAY_BUFFER, m_handle);
		glBufferData(GL_ARRAY_BUFFER, data.size_bytes(), data.data(), GL_STATIC_DRAW);
	}


	void VertexBuffer::Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, m_handle);
	}
	void VertexBuffer::Unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::SetData(std::span<float> data) {
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, data.size_bytes(), data.data());
	}

}


// Engine