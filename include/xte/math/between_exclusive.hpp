#ifndef DETAIL_XTE_HEADER_MATH_BETWEEN_EXCLUSIVE
#	define DETAIL_XTE_HEADER_MATH_BETWEEN_EXCLUSIVE
#
#	include "../math/less.hpp"
#	include "../trait/is_arithmetic.hpp"

namespace xte {
	[[nodiscard]] constexpr bool between_exclusive(xte::is_arithmetic auto x, xte::is_arithmetic auto limit0, xte::is_arithmetic auto limit1) noexcept {
		return (xte::less(limit0, x) && xte::less(x, limit1))
			|| (xte::less(limit1, x) && xte::less(x, limit0));
	}
}

#endif
