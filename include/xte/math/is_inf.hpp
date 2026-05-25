#ifndef DETAIL_XTE_HEADER_MATH_IS_INF
#	define DETAIL_XTE_HEADER_MATH_IS_INF
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <cmath>

namespace xte {
	[[nodiscard]] constexpr bool is_inf(xte::is_number auto x) noexcept {
		if constexpr (xte::is_float<decltype(x)>) {
			return std::isinf(x);
		} else {
			return false;
		}
	}
}

#endif
