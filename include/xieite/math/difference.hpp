#pragma once
#include <cmath> // std::abs
#include <concepts> // std::floating_point, std::integral
#include <type_traits> // std::make_unsigned_t

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::make_unsigned<Integral> difference(const Integral a, const Integral b) noexcept {
		using UnsignedIntegral = std::make_unsigned_t<Integral>;
		
		return (a > b) ? (static_cast<UnsignedIntegral>(a) - static_cast<UnsignedIntegral>(b)) : (static_cast<UnsignedIntegral>(b) - static_cast<UnsignedIntegral>(a));
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]]
	constexpr FloatingPoint difference(const FloatingPoint a, const FloatingPoint b) noexcept {
		return std::abs(a - b);
	}
}
