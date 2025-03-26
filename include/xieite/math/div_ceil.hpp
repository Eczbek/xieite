#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_CEIL
#	define DETAIL_XIEITE_HEADER_MATH_DIV_CEIL
#
#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_ceil(T dividend, T divisor) {
		if constexpr (std::floating_point<T>) {
			return std::ceil(dividend / divisor);
		} else {
			return static_cast<T>(dividend / divisor + !!(dividend % divisor) * (xieite::sign(dividend, divisor) > 0));
		}
	}
}

#endif
