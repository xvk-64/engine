#pragma once

#include <memory>
#include "VertexBuffer.h"

namespace Engine {

	class VertexArray {
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) = 0;

		virtual void SetIndices(std::span<uint32_t> indices) = 0;
		virtual size_t GetIndexCount() = 0;

		// Defined in implementation
		static std::unique_ptr<VertexArray> Create();
	};

} // Engine
