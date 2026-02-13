#ifndef DETAIL_XTE_HEADER_MATH_CEIL
#	define DETAIL_XTE_HEADER_MATH_CEIL
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <cmath>

namespace xte {
	inline constexpr auto ceil = [][[nodiscard]](xte::is_number auto x) static noexcept -> decltype(x) {
		if constexpr (xte::is_float<decltype(x)>) {
			return std::ceil(x);
		} else {
			return x;
		}
	};
}

#endif
