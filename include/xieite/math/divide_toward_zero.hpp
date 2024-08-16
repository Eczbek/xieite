#ifndef XIEITE_HEADER_MATH_DIVIDE_TOWARD_ZERO
#	define XIEITE_HEADER_MATH_DIVIDE_TOWARD_ZERO

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic divideTowardZero(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::floor(dividend / divisor) + ((dividend < 0) != (divisor < 0));
		} else {
			return dividend / divisor;
		}
	}
}

#endif
