#pragma once

#include <string>
#include <glad/glad.h>

namespace Engine::OpenGL {

	// Represents a single vertex or fragment shader file.
	class ShaderUnit {
	public:
		ShaderUnit() = delete;
		ShaderUnit(GLenum shaderType, const std::string& shaderSrc);

		~ShaderUnit();


		uint32_t GetHandle() const {return m_handle;}

	private:
		// The handle OpenGL uses to refer to this shader
		uint32_t m_handle;
	};

}
