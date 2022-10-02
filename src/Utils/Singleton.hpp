#pragma once

#include <concepts>

namespace Engine {

	template <typename T>
	class Singleton {
	public:
		static T& Get() ;

		virtual void Init() = 0;

		virtual void Shutdown() = 0;

	protected:
		explicit Singleton<T>() = default;
	};

	template <typename T>
	T& Singleton<T>::Get() {
		static_assert(std::is_default_constructible<T>());

		static T instance;

		return instance;
	}

} // Engine