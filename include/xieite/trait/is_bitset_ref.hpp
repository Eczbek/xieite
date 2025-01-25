#pragma once

#include <concepts>

namespace xieite {
	template<typename T>
	concept is_bitset_ref = requires (T x) {
		x.~T(); // TODO: Use `std::is_destructible`?
		{ x = true } -> std::same_as<T&>;
		{ x = x } -> std::same_as<T&>;
		x.operator bool();
		{ ~x } -> std::same_as<bool>;
		{ x.flip() } -> std::same_as<T&>;
	};
}
