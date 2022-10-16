#include "VertexArray.h"
#include "Graphics/VertexArray.h"


namespace Engine::OpenGL {
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_handle);

		// Create index buffer
		glBindVertexArray(m_handle);

		glGenBuffers(1, &m_indexHandle);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexHandle);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);
	}

	VertexArray::~VertexArray() {
		// Clean up
		glDeleteBuffers(1, &m_indexHandle);
		glDeleteVertexArrays(1, &m_handle);
	}


	void VertexArray::AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) {
		Bind();
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout.GetElements()) {
			glVertexAttribPointer(m_vertexAttributeIndex,
			                      element.GetComponentCount(),
			                      GL_FLOAT, // TODO
			                      GL_FALSE, // Not normalised
			                      layout.GetStride(),
			                      (const void*)element.offset);
			glEnableVertexAttribArray(m_vertexAttributeIndex);
			m_vertexAttributeIndex++;
		}

		m_vertexBuffers.push_back(std::move(vertexBuffer));
	}

	void VertexArray::SetIndices(std::span<uint32_t> indices) {
		m_indexCount = indices.size();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexHandle);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size_bytes(), indices.data(), GL_STATIC_DRAW);
	}
}

// Engine