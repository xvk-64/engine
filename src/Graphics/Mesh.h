#pragma once

#include <utility>

#include "VertexArray.h"

namespace Engine {

	class Mesh {
	public:
		Mesh() = delete;
		explicit Mesh(std::string name) : m_name{std::move(name)}, m_vertexArray{VertexArray::Create()} {};


		VertexArray& GetVertexArray() {return *m_vertexArray;}

		const std::string& GetName() {return m_name;}

	private:
		std::unique_ptr<VertexArray> m_vertexArray;
		std::string m_name;
	};

} // Engine
