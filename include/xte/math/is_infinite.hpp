#ifndef DETAIL_XTE_HEADER_MATH_IS_INFINITE
#	define DETAIL_XTE_HEADER_MATH_IS_INFINITE
#
#	include "../math/abs.hpp"
#	include "../trait/is_number.hpp"
#	include <limits>

namespace xte {
	inline constexpr auto is_infinite = [][[nodiscard]](xte::is_number auto x) static noexcept {
		if constexpr (std::numeric_limits<decltype(x)>::has_infinity) {
			return xte::abs(x) == std::numeric_limits<decltype(x)>::infinity();
		} else {
			return false;
		}
	};
}

#endif
