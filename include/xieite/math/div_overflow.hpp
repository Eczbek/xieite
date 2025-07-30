#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_DIV_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool div_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		if constexpr (using Type = decltype(first); !std::signed_integral<Type>) {
			return (... || !rest);
		} else {
			const bool is_min = first == std::numeric_limits<Type>::min();
			bool result = false;
			(void)(... && ((result = !rest || (rest == -is_min)), (rest == 1)));
			return result;
		}
	}
}

#endif
