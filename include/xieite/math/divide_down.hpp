#ifndef XIEITE_HEADER_MATH_DIVIDE_DOWN
#	define XIEITE_HEADER_MATH_DIVIDE_DOWN

#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral divideDown(const Integral dividend, const Integral divisor) noexcept {
		return dividend / divisor;
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional divideDown(const Fractional dividend, const Fractional divisor) noexcept {
		return std::floor(dividend / divisor) + (xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
