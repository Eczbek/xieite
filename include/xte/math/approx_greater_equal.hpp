#ifndef DETAIL_XTE_HEADER_MATH_APPROX_GREATER_EQUAL
#	define DETAIL_XTE_HEADER_MATH_APPROX_GREATER_EQUAL
#
#	include "../math/approx_equal.hpp"
#	include "../math/less.hpp"
#	include "../trait/is_arithmetic.hpp"

namespace xte {
	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y) noexcept {
		return xte::less(y, x) || xte::approx_equal(x, y);
	}

	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y, xte::is_arithmetic auto epsilon) noexcept {
		return xte::less(y, x) || xte::approx_equal(x, y, epsilon);
	}
}

#endif
