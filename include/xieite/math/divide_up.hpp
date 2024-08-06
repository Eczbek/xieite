#ifndef XIEITE_HEADER_MATH_DIVIDE_UP
#	define XIEITE_HEADER_MATH_DIVIDE_UP

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ divideUp(const Arithmetic_ dividend, const Arithmetic_ divisor) {
		if constexpr (std::floating_point<Arithmetic_>) {
			return std::ceil(dividend / divisor);
		} else {
			return dividend / divisor + !!(dividend % divisor) * (xieite::math::sign(dividend, divisor) > 0);
		}
	}
}

#endif
