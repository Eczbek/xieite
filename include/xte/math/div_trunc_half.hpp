#ifndef DETAIL_XTE_HEADER_MATH_DIV_TRUNC_HALF
#	define DETAIL_XTE_HEADER_MATH_DIV_TRUNC_HALF
#
#	include "../math/abs.hpp"
#	include "../math/floor.hpp"
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_trunc_half(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			auto quot = static_cast<common_type>(dividend);
			common_type fraction = 0;
			return (..., (fraction = xte::rem(quot /= static_cast<common_type>(divisors), 1), quot = xte::floor(quot) + (quot < 0) + (fraction > 0.5) - (fraction < -0.5)));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>(xte::abs(dividend));
			auto sign = static_cast<std::make_signed_t<common_type>>(xte::sign(dividend));
			(void)(..., (sign = xte::sign(sign, divisors), quot = quot / static_cast<unsigned_type>(xte::abs(divisors)) + (xte::rem(quot, divisors) > (xte::abs(divisors) / 2))));
			return static_cast<common_type>(quot * static_cast<unsigned_type>(sign));
		}
	};
}

#endif
