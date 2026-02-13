#ifndef DETAIL_XTE_HEADER_MATH_APPROX_EQUAL
#	define DETAIL_XTE_HEADER_MATH_APPROX_EQUAL
#
#	include "../func/visitor.hpp"
#	include "../math/abs.hpp"
#	include "../math/between.hpp"
#	include "../math/diff.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr bool approx_equal(xte::is_number auto x, xte::is_number auto y) noexcept {
		if constexpr (using Common = std::common_type_t<decltype(x), decltype(y)>; xte::is_float<Common>) {
			auto diff = xte::diff(x, y);
			return diff <= (std::numeric_limits<Common>::epsilon() * (xte::between(diff, 0, 1, false, false) ? (1 / diff) : diff));
		} else {
			return static_cast<Common>(x) == static_cast<Common>(y);
		}
	}

	[[nodiscard]] constexpr bool approx_equal(xte::is_number auto x, xte::is_number auto y, xte::is_number auto epsilon) noexcept {
		return xte::diff(x, y) <= xte::abs(epsilon);
	}
}

#endif
