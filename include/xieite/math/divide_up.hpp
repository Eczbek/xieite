#ifndef XIEITE_HEADER_MATH_DIVIDE_UP
#	define XIEITE_HEADER_MATH_DIVIDE_UP

#	include <cmath>
#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ divideUp(const Integral_ dividend, const Integral_ divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) - !!(dividend % divisor) * xieite::math::splitBoolean(xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ divideUp(const Fractional_ dividend, const Fractional_ divisor) noexcept {
		return std::ceil(dividend / divisor) - (xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
