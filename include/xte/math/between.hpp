#ifndef DETAIL_XTE_HEADER_MATH_BETWEEN
#	define DETAIL_XTE_HEADER_MATH_BETWEEN
#
#	include "../math/less_equal.hpp"
#	include "../trait/is_arithmetic.hpp"

namespace xte {
	[[nodiscard]] constexpr bool between(xte::is_arithmetic auto x, xte::is_arithmetic auto limit0, xte::is_arithmetic auto limit1) noexcept {
		return (xte::less_equal(limit0, x) && xte::less_equal(x, limit1))
			|| (xte::less_equal(limit1, x) && xte::less_equal(x, limit0));
	}
}

#endif
