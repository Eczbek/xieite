#ifndef DETAIL_XTE_HEADER_MATH_APPROX_EQUAL
#	define DETAIL_XTE_HEADER_MATH_APPROX_EQUAL
#
#	include "../math/abs.hpp"
#	include "../math/diff.hpp"
#	include "../math/equal.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr bool approx_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(x), decltype(y)>; xte::is_float<common_type>) {
			auto diff = xte::diff(x, y);
			return diff <= (std::numeric_limits<common_type>::epsilon() * (((0 < diff) && (diff < 1)) ? (1 / diff) : diff));
		} else {
			return xte::equal(x, y);
		}
	}

	[[nodiscard]] constexpr bool approx_equal(xte::is_arithmetic auto x, xte::is_arithmetic auto y, xte::is_arithmetic auto epsilon) noexcept {
		return xte::diff(x, y) <= xte::abs(epsilon);
	}
}

#endif
