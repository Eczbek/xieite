#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_TRUNC
#	define DETAIL_XIEITE_HEADER_MATH_DIV_TRUNC
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_trunc(T dividend, T divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(dividend / divisor) + ((dividend < 0) != (divisor < 0));
		} else {
			return dividend / divisor;
		}
	}
}

#endif
