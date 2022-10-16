#pragma once

#include <string>
#include <glm/glm.hpp>
#include <memory>

namespace Engine {

// Represents a shader
	class Shader {
	public:
		virtual ~Shader() = default;


		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetBool(const std::string& name, bool value) = 0;
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;


		// Defined in implementation
		static std::unique_ptr<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}