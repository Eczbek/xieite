#ifndef XIEITE_HEADER_MATH_DIVIDE_FLOOR
#	define XIEITE_HEADER_MATH_DIVIDE_FLOOR

#	include <cmath>
#	include <concepts>
#	include "../math/divide_up.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ divideFloor(const Integral_ dividend, const Integral_ divisor) noexcept {
		return xieite::math::divideUp(dividend, divisor) - !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ divideFloor(const Fractional_ dividend, const Fractional_ divisor) noexcept {
		return std::floor(dividend / divisor);
	}
}

#endif
