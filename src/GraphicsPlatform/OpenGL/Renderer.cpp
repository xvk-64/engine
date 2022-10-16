#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Renderer.h"

namespace Engine::OpenGL {

	Renderer::Renderer() {
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}


	void Renderer::SetClearColour(const glm::vec4& colour) {
		glClearColor(colour.r, colour.g, colour.b, colour.a);
	}
	void Renderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::DrawArray(const std::unique_ptr<VertexArray>& vertexArray) {
		vertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}