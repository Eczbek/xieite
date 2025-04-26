#ifndef DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#	define DETAIL_XIEITE_HEADER_MATH_SUB_OVERFLOW
#
#	include <concepts>
#	include <limits>
#	include "../math/neg.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr bool sub_overflow(Arith first, Ariths... rest) noexcept {
		return sizeof...(Ariths)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && (xieite::neg(rest) ? ((std::numeric_limits<Arith>::max() + rest) < first) : ((std::numeric_limits<Arith>::min() + rest) > first))) {
					return true;
				}
				first -= static_cast<decltype(first)>(rest);
				return false;
			})());
	}
}

#endif
