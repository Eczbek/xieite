#ifndef DETAIL_XTE_HEADER_MATH_DIV_FLOOR
#	define DETAIL_XTE_HEADER_MATH_DIV_FLOOR
#
#	include "../math/abs.hpp"
#	include "../math/floor.hpp"
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_floor(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = static_cast<common_type>(dividend);
			return (..., (quot = xte::floor(quot / static_cast<common_type>(divisors))));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + static_cast<unsigned_type>(!!xte::rem(quot, divisors) * (sign < 0))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	};
}

#endif
