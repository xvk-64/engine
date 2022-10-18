#include "World.h"

namespace Engine {

	World::World(Application& application) : m_application(application) {
		// When we create a new camera, it needs to have the correct aspect ratio.
		registry.on_construct<CameraComponent>().connect<&World::OnCameraAdded>(this);
	}


	void World::Update() {
		if (m_currentScene) {
			m_currentScene->Update(*this);
		}

		// If there is a new scene to switch to, switch to it.
		if (m_nextScene) {
			if (m_currentScene)
				// Detach the current scene
				m_currentScene->OnDetach(*this);

			m_currentScene = std::move(m_nextScene);

			// Attach the new scene
			m_currentScene->OnAttach(*this);
		}
	}

	void World::OnViewportResize(uint32_t width, uint32_t height) {
		m_viewportWidth = width;
		m_viewportHeight = height;

		// Update scene cameras
		auto view = registry.view<CameraComponent>();
		for (auto entity : view) {
			auto& cameraComponent = view.get<CameraComponent>(entity);
			cameraComponent.camera.SetViewportSize(width, height);
		}
	}

	void World::OnCameraAdded(entt::registry& registry, entt::entity entity) {
		auto& cameraComponent = registry.get<CameraComponent>(entity);
		cameraComponent.camera.SetViewportSize(m_viewportWidth, m_viewportHeight);
	}
}