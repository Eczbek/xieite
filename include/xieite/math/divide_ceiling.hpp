#ifndef XIEITE_HEADER_MATH_DIVIDE_CEILING
#	define XIEITE_HEADER_MATH_DIVIDE_CEILING

#	include <cmath>
#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideCeiling(const Integer dividend, const Integer divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) + !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint divideCeiling(const FloatingPoint dividend, const FloatingPoint divisor) noexcept {
		return std::ceil(dividend / divisor);
	}
}

#endif
