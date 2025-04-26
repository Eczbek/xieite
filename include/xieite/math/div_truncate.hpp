#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_TRUNCATE
#	define DETAIL_XIEITE_HEADER_MATH_DIV_TRUNCATE
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_truncate(Arith lhs, Arith rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::floor(lhs / rhs) + ((lhs < 0) != (rhs < 0));
		} else {
			return lhs / rhs;
		}
	}
}

#endif
