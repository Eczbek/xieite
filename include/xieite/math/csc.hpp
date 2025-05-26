#ifndef DETAIL_XIEITE_HEADER_MATH_CSC
#	define DETAIL_XIEITE_HEADER_MATH_CSC
#
#	include <cmath>
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto csc(xieite::is_arith auto theta) noexcept {
		return 1 / std::sin(theta);
	}
}

#endif
