#ifndef XIEITE_HEADER_MATH_DIVIDE_CEILING
#	define XIEITE_HEADER_MATH_DIVIDE_CEILING

#	include <cmath>
#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral divideCeiling(const Integral dividend, const Integral divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) + !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional divideCeiling(const Fractional dividend, const Fractional divisor) noexcept {
		return std::ceil(dividend / divisor);
	}
}

#endif
