#ifndef XIEITE_HEADER_MATH_DIVIDE_HALF_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_DIVIDE_HALF_TOWARD_INFINITY

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ divideHalfTowardInfinity(const Arithmetic_ dividend, const Arithmetic_ divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic_>) {
			const Arithmetic_ result = dividend / divisor;
			return std::floor(result) + (result < 0) + (std::fmod(std::abs(result), 1) >= 0.5) * xieite::math::sign(result);
		} else {
			return static_cast<Arithmetic_>(dividend / divisor + ((dividend % divisor * xieite::math::sign(dividend)) >= (divisor / 2 * xieite::math::sign(divisor) + !!(divisor % 2))) * xieite::math::sign(dividend, divisor));
		}
	}
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
