#ifndef DETAIL_XIEITE_HEADER_MATH_SEC
#	define DETAIL_XIEITE_HEADER_MATH_SEC
#
#	include <cmath>
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto sec(xieite::is_arith auto theta) noexcept {
		return 1 / std::cos(theta);
	}
}

#endif
