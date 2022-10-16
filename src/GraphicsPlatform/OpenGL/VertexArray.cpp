#include "VertexArray.h"
#include "Graphics/VertexArray.h"


namespace Engine::OpenGL {
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_handle);
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_handle);
	}


	void VertexArray::AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) {
		Bind();
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout.GetOffsets()) {
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
}

// Engine