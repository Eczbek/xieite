#ifndef DETAIL_XIEITE_HEADER_MATH_ADD_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_ADD_OVERFLOW
#
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool add_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		if constexpr (using Type = decltype(first); std::floating_point<Type>) {
			return false;
		} else {
			return xieite::unroll<sizeof...(rest)>([&first, rest...]<std::size_t... i> -> bool {
				return (... || ([&first](auto next) -> bool {
					if (static_cast<Type>(next) && (xieite::neg(first) ? ((std::numeric_limits<Type>::min() - first) > next) : ((std::numeric_limits<decltype(first)>::max() - first) < next))) {
						return true;
					}
					if constexpr (i < (sizeof...(rest) - 1)) {
						first = static_cast<Type>(first + next);
					}
					return false;
				}(rest)));
			});
		}
	}
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103876
