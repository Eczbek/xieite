#ifndef XIEITE_HEADER_MATH_DIVIDE_FLOOR
#	define XIEITE_HEADER_MATH_DIVIDE_FLOOR

#	include <cmath>
#	include <concepts>
#	include "../math/divide_up.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideFloor(const Integer dividend, const Integer divisor) noexcept {
		return xieite::math::divideUp(dividend, divisor) - !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint divideFloor(const FloatingPoint dividend, const FloatingPoint divisor) noexcept {
		return std::floor(dividend / divisor);
	}
}

#endif
