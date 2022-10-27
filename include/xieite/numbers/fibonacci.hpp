#pragma once
#include <concepts>

namespace xieite::numbers {
	template<std::integral auto N, typename T = decltype(N)>
	constexpr T fibonacci = xieite::numbers::fibonacci<N - 1, T> + xieite::numbers::fibonacci<N - 2, T>;

	template<typename T>
	constexpr T fibonacci<static_cast<T>(1), T> = static_cast<T>(1);

	template<typename T>
	constexpr T fibonacci<static_cast<T>(0), T> = static_cast<T>(0);
}
