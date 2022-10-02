#pragma once

#include <functional>
#include <set>
#include <unordered_set>
#include <utility>

namespace Engine {

	template<typename... Args>
	class Event;

	template<typename... Args>
	class EventHandler {
		friend class Event<Args...>;

	private:
		std::function<void(Args...)> m_handlerFunction;

		int m_handlerID;
		static int m_handlerIDCounter;

	public:
		explicit EventHandler(const std::function<void(Args...)>& handlerFunction)
				: m_handlerFunction{handlerFunction}, m_handlerID{m_handlerIDCounter++} { }

		bool operator ==(const EventHandler<Args...>& other) {
			return m_handlerID == other.m_handlerID;
		}

		// Copy constructor
		EventHandler(const EventHandler<Args...>& src) noexcept
			: m_handlerFunction(src.m_handlerFunction), m_handlerID(src.m_handlerID) { }

		// Move assignment
		EventHandler& operator=(EventHandler<Args...>&& src) noexcept {
			std::swap(m_handlerFunction, src.m_handlerFunction);
			m_handlerID = src.m_handlerID;

			return *this;
		}
	};

	template<typename... Args>
	int EventHandler<Args...>::m_handlerIDCounter{0};


	template<typename... Args>
	class Event {
	public:
		void AddHandler(EventHandler<Args...> handler) {
			if (std::find(m_handlers.begin(), m_handlers.end(), handler) == m_handlers.end())
				m_handlers.push_back(handler);
			else {
				// Handler already added
			}
		}

		void RemoveHandler(EventHandler<Args...> handler) {
			m_handlers.erase(std::find(m_handlers.begin(), m_handlers.end(), handler));
		}

		void Invoke(Args... args) {
			for (auto& handler : m_handlers)
				handler.m_handlerFunction(args...);
		}

	private:
		std::vector<EventHandler<Args...>> m_handlers;
	};
}
