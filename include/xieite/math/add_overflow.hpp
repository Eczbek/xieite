#ifndef DETAIL_XIEITE_HEADER_MATH_ADD_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_ADD_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../fn/unroll.hpp"
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr bool add_overflow(Arith first, Ariths... rest) noexcept {
		return sizeof...(Ariths)
			&& first
			&& xieite::unroll<sizeof...(Ariths)>([&first, rest...]<std::size_t... i> -> bool {
				return (... || ([&first, rest] -> bool {
					if (rest && (xieite::neg(first) ? ((std::numeric_limits<Arith>::min() - first) > rest) : ((std::numeric_limits<Arith>::max() - first) < rest))) {
						return true;
					}
					if constexpr (i < (sizeof...(Ariths) - 1)) {
						first += static_cast<Arith>(rest);
					}
					return false;
				})());
			});
	}
}

#endif
