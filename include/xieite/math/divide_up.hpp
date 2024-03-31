#ifndef XIEITE_HEADER_MATH_DIVIDE_UP
#	define XIEITE_HEADER_MATH_DIVIDE_UP

#	include <cmath>
#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral divideUp(const Integral dividend, const Integral divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) - !!(dividend % divisor) * xieite::math::splitBoolean(xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional divideUp(const Fractional dividend, const Fractional divisor) noexcept {
		return std::ceil(dividend / divisor) - (xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
