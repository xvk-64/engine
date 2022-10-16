#pragma once

#include <initializer_list>
#include <array>
#include <span>
#include <vector>

namespace Engine {
	enum class BufferDataType {
		Float,
		Float2,
		Float3,
		Float4,
		// ...
	};

	struct BufferElement {
		BufferElement(BufferDataType type) : type{type} {}

		BufferDataType type;
		size_t offset = 0;

		uint32_t GetComponentCount() const {
			switch (type) {
				case BufferDataType::Float:     return 1;
				case BufferDataType::Float2:    return 2;
				case BufferDataType::Float3:    return 3;
				case BufferDataType::Float4:    return 4;
			}
			return 0;
		}

		std::size_t GetSize() const {
			switch (type) {
				case BufferDataType::Float:
				case BufferDataType::Float2:
				case BufferDataType::Float3:
				case BufferDataType::Float4:
					return GetComponentCount() * sizeof(float);
			}
			return 0;
		}
	};

	class BufferLayout {
	public:

		BufferLayout() = delete;
		BufferLayout(const std::initializer_list<BufferElement> elements) : m_elements(elements) {
			for (auto& element : m_elements) {
				element.offset = m_stride;
				m_stride += element.GetSize();
			}
		}

		std::size_t GetStride() const {return m_stride;}
		std::span<const BufferElement> GetOffsets() const {return m_elements;}

	private:
		std::size_t m_stride = 0;
		std::vector<BufferElement> m_elements;
	};

} // Engine
