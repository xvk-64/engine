#include "ShaderUnit.h"

namespace Engine::OpenGL {

	ShaderUnit::ShaderUnit(GLenum shaderType, const std::string& shaderSrc) {
		m_handle = glCreateShader(shaderType);

		auto srcString = shaderSrc.c_str();

		// Add source to shader, 1 string, no lengths array.
		glShaderSource(m_handle, 1, &srcString, nullptr);

		// Compile the shader
		glCompileShader(m_handle);

//		// Print compile errors
//		int success;
//		glGetShaderiv(m_handle, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetShaderInfoLog(m_handle, 512, nullptr, infoLog);
//			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//		}
	}

	ShaderUnit::~ShaderUnit() {
		glDeleteShader(m_handle);
	}
}