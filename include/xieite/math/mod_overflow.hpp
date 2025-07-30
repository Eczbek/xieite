#ifndef DETAIL_XIEITE_HEADER_MATH_MOD_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_MOD_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../trait/is_arith.hpp"

namespace xieite::math {
	[[nodiscard]] constexpr bool mod_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		if constexpr (using Type = decltype(first); !std::signed_integral<Type>) {
			return (... || !rest);
		} else {
			return (sizeof...(rest) && (first == std::numeric_limits<Type>::min()) && (rest...[0] == -1)) || (... || !rest);
		}
	}
}

#endif
