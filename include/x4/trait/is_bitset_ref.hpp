#pragma once

#include <concepts>

namespace x4 {
	template<typename T>
	concept isbitsetref = requires (T x) {
		x.~T();
		{ x = true } -> std::same_as<T&>;
		{ x = x } -> std::same_as<T&>;
		x.operator bool();
		{ ~x } -> std::same_as<bool>;
		{ x.flip() } -> std::same_as<T&>;
	};
}
