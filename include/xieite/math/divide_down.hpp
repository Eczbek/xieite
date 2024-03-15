#ifndef XIEITE_HEADER_MATH_DIVIDE_DOWN
#	define XIEITE_HEADER_MATH_DIVIDE_DOWN

#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideDown(const Integer dividend, const Integer divisor) noexcept {
		return dividend / divisor;
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint divideDown(const FloatingPoint dividend, const FloatingPoint divisor) noexcept {
		return std::floor(dividend / divisor) + (xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
