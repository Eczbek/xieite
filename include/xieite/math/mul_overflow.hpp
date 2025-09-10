#ifndef DETAIL_XIEITE_HEADER_MATH_MUL_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_MUL_OVERFLOW
#
#	include <cstddef>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../math/abs.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool mul_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		using Type = decltype(first);
		return xieite::unroll<sizeof...(rest)>([&first, rest...]<std::size_t... i> -> bool {
			return (... || ([&first](auto next) -> bool {
				if (next && ((xieite::abs((xieite::neg(first) != xieite::neg(next)) ? std::numeric_limits<Type>::min() : std::numeric_limits<Type>::max()) / xieite::abs(first)) < xieite::abs(next))) {
					return true;
				}
				if constexpr (i < (sizeof...(rest) - 1)) {
					first = static_cast<Type>(first * next);
				}
				return false;
			}(rest)));
		});
	}
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103876
