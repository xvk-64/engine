#pragma once

#include <span>
#include <tuple>
#include <memory>
#include "BufferLayout.h"

namespace Engine {

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetData(std::span<float> data) = 0;
		virtual const BufferLayout& GetLayout() = 0;


		// Defined in implementation
		static std::unique_ptr<VertexBuffer> Create(const BufferLayout& layout, std::span<float> data);
	};

} // Engine
