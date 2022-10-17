#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Renderer.h"

namespace Engine::OpenGL {

	Renderer::Renderer() {
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glEnable(GL_DEPTH_TEST);
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

	void Renderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
		glViewport(x, y, width, height);
	}
}