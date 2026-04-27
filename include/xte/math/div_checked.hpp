#ifndef DETAIL_XTE_HEADER_MATH_DIV_CHECKED
#	define DETAIL_XTE_HEADER_MATH_DIV_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/abs.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_signed.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_checked(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(dividend), decltype(divisors)...>; xte::is_float<common_type>) {
			return (!xte::is_finite(dividend) || ... || (!xte::is_finite(divisors) || xte::approx_equal(divisors, 0)))
				? xte::null
				: xte::opt<common_type>((static_cast<common_type>(dividend) / ... / static_cast<common_type>(divisors)));
		} else {
			if ((... || !divisors)) {
				return xte::opt<common_type>(xte::null);
			}
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto quot = static_cast<unsigned_type>((static_cast<unsigned_type>(xte::abs(dividend)) / ... / static_cast<unsigned_type>(xte::abs(divisors))));
			common_type sign = xte::sign(dividend, divisors...);
			if constexpr (xte::is_signed<common_type>) {
				if ((sign == 1) && (quot == xte::abs(std::numeric_limits<common_type>::min()))) {
					return xte::opt<common_type>(xte::null);
				}
			}
			return xte::opt<common_type>(static_cast<common_type>(quot * static_cast<unsigned_type>(sign)));
		}
	};
}

#endif
