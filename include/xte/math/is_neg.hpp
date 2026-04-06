#ifndef DETAIL_XTE_HEADER_MATH_IS_NEG
#	define DETAIL_XTE_HEADER_MATH_IS_NEG
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <cmath>

namespace xte {
	inline constexpr auto is_neg = [][[nodiscard]](xte::is_number auto x) static noexcept -> bool {
		if constexpr (xte::is_float<decltype(x)>) {
			return std::signbit(x);
		} else {
			return x < 0;
		}
	};
}

#endif
