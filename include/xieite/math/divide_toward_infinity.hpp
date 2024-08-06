#ifndef XIEITE_HEADER_MATH_DIVIDE_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_DIVIDE_TOWARD_INFINITY

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ divideTowardInfinity(const Arithmetic_ dividend, const Arithmetic_ divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic_>) {
			return std::ceil(dividend / divisor) - ((dividend < 0) != (divisor < 0));
		} else {
			return dividend / divisor + !!(dividend % divisor) * xieite::math::sign(dividend, divisor);
		}
	}
}

#endif
