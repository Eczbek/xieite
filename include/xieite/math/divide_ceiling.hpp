#ifndef XIEITE_HEADER_MATH_DIVIDE_CEILING
#	define XIEITE_HEADER_MATH_DIVIDE_CEILING

#	include <cmath>
#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ divideCeiling(const Integral_ dividend, const Integral_ divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) + !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ divideCeiling(const Fractional_ dividend, const Fractional_ divisor) noexcept {
		return std::ceil(dividend / divisor);
	}
}

#endif
