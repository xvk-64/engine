#pragma once

#include <functional>
#include <set>
#include <unordered_set>

namespace Engine::Core {

	template<typename T>
	class Event {
	public:
		void AddListener(std::function<void(T)> const& delegate) {
			for (const auto& listener : m_listeners)
				if (CompareDelegates(delegate, listener.delegate))
					return;

			m_listeners.push_back({.delegate=delegate});
		}

		void RemoveListener(std::function<void(T)> const& delegate) {
			for (int i = m_listeners.size() - 1; i--; i >= 0) {
				if (CompareDelegates(delegate, m_listeners[i].delegate))
					m_listeners.erase(std::next(m_listeners.begin(), i));
			}
		};

		void Invoke(T data) {
			for (auto& listener: m_listeners)
				listener.delegate(data);
		};

	private:
		struct Listener {
			const std::function<void(T)> delegate;
		};

		bool CompareDelegates(std::function<void(T)> delegate1, std::function<void(T)> delegate2) {
			auto ptr1 = delegate1.template target<void(*)(T)>();
			auto ptr2 = delegate2.template target<void(*)(T)>();

			return ptr1 == ptr2;
		}

		std::vector<Listener> m_listeners;
	};
}
