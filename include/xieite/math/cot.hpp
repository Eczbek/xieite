#ifndef DETAIL_XIEITE_HEADER_MATH_COT
#	define DETAIL_XIEITE_HEADER_MATH_COT
#
#	include <cmath>
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto cot(xieite::is_arith auto theta) noexcept {
		return std::cos(theta) / std::sin(theta);
	}
}

#endif
