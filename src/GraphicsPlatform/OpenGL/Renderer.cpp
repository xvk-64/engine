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

	void Renderer::DrawIndexed(const VertexArray& vertexArray) {
		vertexArray.Bind();
		glDrawElements(GL_TRIANGLES, vertexArray.GetIndexCount(), GL_UNSIGNED_INT, 0);
	}
}