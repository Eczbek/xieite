#ifndef DETAIL_XTE_HEADER_MATH_APPROX_LESS_EQUAL
#	define DETAIL_XTE_HEADER_MATH_APPROX_LESS_EQUAL
#
#	include "../math/approx_equal.hpp"
#	include "../math/less.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr bool approx_less_equal(xte::is_number auto x, xte::is_number auto y) noexcept {
		return xte::less(x, y) || xte::approx_equal(x, y);
	}

	[[nodiscard]] constexpr bool approx_less_equal(xte::is_number auto x, xte::is_number auto y, xte::is_number auto epsilon) noexcept {
		return xte::less(x, y) || xte::approx_equal(x, y, epsilon);
	}
}

#endif
