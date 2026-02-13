#ifndef DETAIL_XTE_HEADER_MATH_APPROX_EQUAL_SLOPE
#	define DETAIL_XTE_HEADER_MATH_APPROX_EQUAL_SLOPE
#
#	include "../func/visitor.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/is_infinite.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr bool approx_equal_slope(xte::is_number auto x, xte::is_number auto y) noexcept {
		return (xte::is_infinite(x) && xte::is_infinite(y)) || xte::approx_equal(x, y);
	};

	[[nodiscard]] constexpr bool approx_equal_slope(xte::is_number auto x, xte::is_number auto y, xte::is_number auto epsilon) noexcept {
		return (xte::is_infinite(x) && xte::is_infinite(y)) || xte::approx_equal(x, y, epsilon);
	}
}

#endif
