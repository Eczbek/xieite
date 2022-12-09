#pragma once
#include <concepts> // std::floating_point, std::integral
#include <numbers> // std::numbers::pi, std::numbers::pi_v

namespace xieite::math {
	template<typename>
	constexpr double pi = std::numbers::pi;

	template<std::floating_point N>
	constexpr N pi<N> = std::numbers::pi_v<N>;

	template<std::integral N>
	constexpr N pi<N> = 3;
}
