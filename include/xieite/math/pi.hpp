#pragma once
#include <concepts>
#include <numbers>

namespace xieite::math {
	template<typename>
	constexpr double pi = std::numbers::pi;

	template<std::floating_point N>
	constexpr N pi<N> = std::numbers::pi_v<N>;

	template<std::integral N>
	constexpr N pi<N> = 3;
}
