#ifndef XIEITE_HEADER_MATH_DIVIDE_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_DIVIDE_TOWARD_INFINITY

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic divideTowardInfinity(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::ceil(dividend / divisor) - ((dividend < 0) != (divisor < 0));
		} else {
			return static_cast<Arithmetic>(dividend / divisor + !!(dividend % divisor) * xieite::math::sign(dividend, divisor));
		}
	}
}

#endif
