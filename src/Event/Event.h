#pragma once

#include <functional>
#include <set>
#include <unordered_set>

namespace Engine::Event {

	template<typename T>
	class Event {
	public:
		void AddListener(std::function<void(T)> listener) {listeners.};
		void RemoveListener(std::function<void(T)> listener);

	private:
		std::unordered_set<std::function<void(T)>> listeners;
	};

}
