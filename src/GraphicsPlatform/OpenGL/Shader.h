#pragma once

#include "Graphics/Shader.h"
#include "ShaderUnit.h"
#include <glm/gtc/type_ptr.hpp>

namespace Engine::OpenGL {

	class Shader : public Engine::Shader {
	public:
		Shader() = delete;
		Shader(const ShaderUnit& vertex, const ShaderUnit& fragment);

		~Shader() override;


		void Bind() override {glUseProgram(m_handle);}
		void Unbind() override {glUseProgram(0);}

		void SetBool(const std::string& name, bool value) override {glUniform1i(glGetUniformLocation(m_handle, name.c_str()), value);}
		void SetInt(const std::string& name, int value) override {glUniform1i(glGetUniformLocation(m_handle, name.c_str()), value);}
		void SetFloat(const std::string& name, float value) override {glUniform1f(glGetUniformLocation(m_handle, name.c_str()), value);}
		void SetFloat2(const std::string& name, const glm::vec2& value) override {glUniform2f(glGetUniformLocation(m_handle, name.c_str()), value.x, value.y);}
		void SetFloat3(const std::string& name, const glm::vec3& value) override {glUniform3f(glGetUniformLocation(m_handle, name.c_str()), value.x, value.y, value.z);}
		void SetFloat4(const std::string& name, const glm::vec4& value) override {glUniform4f(glGetUniformLocation(m_handle, name.c_str()), value.x, value.y, value.z, value.w);}
		void SetMat4(const std::string& name, const glm::mat4& value) override {{glUniformMatrix4fv(glGetUniformLocation(m_handle, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));}};

	private:
		// OpenGL handle
		uint32_t m_handle;
	};

} // Engine

std::unique_ptr<Engine::Shader> Engine::Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc) {
	Engine::OpenGL::ShaderUnit vertex {GL_VERTEX_SHADER, vertexSrc};
	Engine::OpenGL::ShaderUnit fragment {GL_FRAGMENT_SHADER, fragmentSrc};

	return std::make_unique<Engine::OpenGL::Shader>(vertex, fragment);
}