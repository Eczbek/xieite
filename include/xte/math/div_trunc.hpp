#ifndef DETAIL_XTE_HEADER_MATH_DIV_TRUNC
#	define DETAIL_XTE_HEADER_MATH_DIV_TRUNC
#
#	include "../math/div.hpp"
#	include "../math/floor.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_trunc(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = static_cast<common_type>(dividend);
			return (..., (quot = xte::floor(quot / static_cast<common_type>(divisors)) + (xte::sign(quot, divisors) < 0)));
		} else {
			return xte::div(dividend, divisors...);
		}
	};
}

#endif
