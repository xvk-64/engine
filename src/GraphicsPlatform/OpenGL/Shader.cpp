#include <iostream>
#include "Shader.h"
#include "Graphics/Shader.h"


namespace Engine::OpenGL {
	Shader::Shader(const ShaderUnit& vertex, const ShaderUnit& fragment) {
		m_handle = glCreateProgram();

		// Attach shader units
		glAttachShader(m_handle, vertex.GetHandle());
		glAttachShader(m_handle, fragment.GetHandle());

		// Link shader
		glLinkProgram(m_handle);


		// Print any linking errors
		int  success;
		char infoLog[512];
		glGetProgramiv(m_handle, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(m_handle, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

	}

	Shader::~Shader() {
		glDeleteProgram(m_handle);
	}
}

// Engine