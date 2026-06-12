#ifndef DETAIL_XTE_HEADER_MATH_IS_FINITE
#	define DETAIL_XTE_HEADER_MATH_IS_FINITE
#
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include <cmath>

namespace xte {
	[[nodiscard]] constexpr bool is_finite(xte::is_arithmetic auto x) noexcept {
		if constexpr (xte::is_float<decltype(x)>) {
			return std::isfinite(x);
		} else {
			return true;
		}
	}
}

#endif
