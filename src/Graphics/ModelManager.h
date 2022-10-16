#pragma once

#include <map>
#include <string>
#include <memory>
#include "Mesh.h"

namespace Engine {

	class ModelManager {
	public:
		ModelManager();




		std::shared_ptr<Mesh> GetStaticMesh(const std::string& name) {return m_staticMeshes.at(name);}

	private:
		void AddCubeStaticMesh();

		std::map<std::string, std::shared_ptr<Mesh>> m_staticMeshes;
	};

} // Engine
