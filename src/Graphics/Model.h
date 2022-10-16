#pragma once

#include <vector>
#include <memory>
#include "Mesh.h"

namespace Engine {

	class Model {
	public:
		void AddMesh(const std::shared_ptr<Mesh>& mesh) {m_meshes.push_back(mesh);}
		const std::vector<std::shared_ptr<Mesh>>& GetMeshes() {return m_meshes;}

	private:
		std::vector<std::shared_ptr<Mesh>> m_meshes;
	};

} // Engine
