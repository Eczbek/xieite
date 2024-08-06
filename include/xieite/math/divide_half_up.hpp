#ifndef XIEITE_HEADER_MATH_DIVIDE_HALF_UP
#	define XIEITE_HEADER_MATH_DIVIDE_HALF_UP

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ divideHalfUp(const Arithmetic_ dividend, const Arithmetic_ divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic_>) {
			const Arithmetic_ result = dividend / divisor;
			const Arithmetic_ fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional >= 0.5) - (fractional < -0.5);
		} else {
			const int quotientSign = xieite::math::sign(dividend, divisor);
			return dividend / divisor + ((dividend % divisor * xieite::math::sign(dividend)) >= (divisor / 2 * xieite::math::sign(divisor) + ((divisor % 2) || (quotientSign < 0)))) * quotientSign;
		}
	}
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
