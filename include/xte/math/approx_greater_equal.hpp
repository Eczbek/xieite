#ifndef DETAIL_XTE_HEADER_MATH_APPROX_GREATER_EQUAL
#	define DETAIL_XTE_HEADER_MATH_APPROX_GREATER_EQUAL
#
#	include "../math/approx_equal.hpp"
#	include "../math/greater_equal.hpp"
#	include "../trait/is_arithmetic.hpp"

namespace xte {
	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y) noexcept {
		return xte::approx_equal(x, y) || xte::greater_equal(x, y);
	}

	[[nodiscard]] constexpr bool approx_greater_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y, xte::is_arithmetic auto epsilon) noexcept {
		return xte::approx_equal(x, y, epsilon) || xte::greater_equal(x, y);
	}
}

#endif
