#ifndef XIEITE_HEADER_MATH_DIVIDE_FLOOR
#	define XIEITE_HEADER_MATH_DIVIDE_FLOOR

#	include <cmath>
#	include <concepts>
#	include "../math/divide_up.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral divideFloor(const Integral dividend, const Integral divisor) noexcept {
		return xieite::math::divideUp(dividend, divisor) - !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional divideFloor(const Fractional dividend, const Fractional divisor) noexcept {
		return std::floor(dividend / divisor);
	}
}

#endif
