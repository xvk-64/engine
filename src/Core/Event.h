#pragma once

#include <functional>
#include <set>
#include <unordered_set>
#include <utility>

namespace Engine::Core {

	template<typename T>
	class Event {
	public:
		class Listener {
		friend class Event<T>;
		public:
			explicit Listener(std::function<void(T)> delegate, std::function<void(void)> cleanup)
				: m_delegate(delegate), m_cleanup(std::move(cleanup)) {}
			~Listener() {
				m_cleanup();
			}

		private:
			std::function<void(T)> m_delegate;
			std::function<void(void)> m_cleanup;
		};

		Listener AddListener(std::function<void(T)> const& delegate) {
			auto delegatePtr = std::make_shared<std::function<void(T)>>(delegate);
			m_listeners.insert(delegatePtr);

			Listener listener{delegate, [this, delegatePtr](){RemoveListener(delegatePtr);}};

			return listener;
		}

		void Invoke(T data) {
			for (auto& listener: m_listeners)
				(*listener)(data);
		};

	private:
		void RemoveListener(std::shared_ptr<std::function<void(T)>> listener) {
			m_listeners.erase(listener);
		}

		std::set<std::shared_ptr<std::function<void(T)>>> m_listeners;
	};
}
