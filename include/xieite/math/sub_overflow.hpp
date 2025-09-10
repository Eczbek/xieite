#ifndef DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#
#	include <cstddef>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto sub_overflow(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		using Type = decltype(first);
		return xieite::unroll<sizeof...(rest)>([&first, rest...]<std::size_t... i> -> bool {
			return (... || ([&first](auto next) -> bool {
				if (static_cast<Type>(next) && (xieite::neg(next) ? ((std::numeric_limits<Type>::max() + next) < first) : ((std::numeric_limits<Type>::min() + next) > first))) {
					return true;
				}
				if constexpr (i < (sizeof...(rest) - 1)) {
					first = static_cast<Type>(first - next);
				}
				return false;
			}(rest)));
		});
	}
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=103876
