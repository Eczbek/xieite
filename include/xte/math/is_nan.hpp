#ifndef DETAIL_XTE_HEADER_MATH_IS_NAN
#	define DETAIL_XTE_HEADER_MATH_IS_NAN
#
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr bool is_nan(xte::is_number auto x) noexcept {
		return x != x;
	}
}

#endif
