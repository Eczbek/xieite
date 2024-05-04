#ifndef XIEITE_HEADER_MATH_DIVIDE_DOWN
#	define XIEITE_HEADER_MATH_DIVIDE_DOWN

#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ divideDown(const Integral_ dividend, const Integral_ divisor) noexcept {
		return dividend / divisor;
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ divideDown(const Fractional_ dividend, const Fractional_ divisor) noexcept {
		return std::floor(dividend / divisor) + (xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
