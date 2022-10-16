#pragma once

#include <memory>
#include "VertexBuffer.h"

namespace Engine {

	class VertexArray {
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) = 0;

		virtual void SetIndices(std::span<uint32_t> indices) = 0;
		virtual size_t GetIndexCount() const = 0;

		// Defined in implementation
		static std::unique_ptr<VertexArray> Create();
	};

} // Engine
