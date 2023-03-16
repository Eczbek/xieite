#pragma once
#include <concepts> // std::floating_point, std::integral
#include <numbers> // std::numbers::pi_v

namespace xieite::math {
	template<typename>
	static constexpr double pi = std::numbers::pi;

	template<std::floating_point FloatingPoint>
	constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;

	template<std::integral Integral>
	constexpr Integral pi<Integral> = 3;
}
