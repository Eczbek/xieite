#ifndef DETAIL_XTE_HEADER_MATH_FLOOR
#	define DETAIL_XTE_HEADER_MATH_FLOOR
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <cmath>

namespace xte {
	inline constexpr auto floor = [][[nodiscard]](xte::is_number auto x) static noexcept -> decltype(x) {
		if constexpr (xte::is_float<decltype(x)>) {
			return std::floor(x);
		} else {
			return x;
		}
	};
}

#endif
