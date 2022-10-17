#pragma once

#include "ECS/System.h"
#include "Graphics/Shader.h"
#include "Core/Application.h"

namespace Engine {

	class RenderSystem : public System {
	public:
		RenderSystem() {
			m_shader = Shader::FromFile("assets/shaders/shader.vert", "assets/shaders/shader.frag");
		}

		void Update(World& world) override {
			auto& renderer = Application::Get().GetRenderer();

			m_shader->Bind();

			// Find the world camera.
			glm::mat4 cameraViewProjection = glm::mat4(1.0f); // Combines view and projection matrix.
			{
				auto view = world.registry.view<TransformComponent, CameraComponent>();
				for (auto entity : view) {
					auto [transformComponent, cameraComponent] = view.get<TransformComponent, CameraComponent>(entity);

					cameraViewProjection = cameraComponent.camera.GetProjection() * glm::inverse(transformComponent.GetTransformMatrix());
				}
			}


			// Get all entities with ModelComponent
			{
				auto view = world.registry.view<ModelComponent, TransformComponent>();

				for (auto entity: view) {
					auto& transformComponent = view.get<TransformComponent>(entity);
					auto& modelComponent = view.get<ModelComponent>(entity);

					m_shader->SetMat4("transform", transformComponent.GetTransformMatrix());
					m_shader->SetMat4("viewProjection", cameraViewProjection);

					// Render all meshes
					for (auto& mesh: modelComponent.model->GetMeshes()) {
						renderer.DrawIndexed(mesh->GetVertexArray());
					}
				}
			}

		}

		std::unique_ptr<Shader> m_shader;
	};

} // Engien
