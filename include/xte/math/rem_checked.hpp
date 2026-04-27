#ifndef DETAIL_XTE_HEADER_MATH_REM_CHECKED
#	define DETAIL_XTE_HEADER_MATH_REM_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/rem.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr auto rem_checked(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(divisors) || xte::approx_equal(divisors, 0)))
			? xte::null
			: xte::opt(xte::rem(dividend, divisors...));
	};
}

#endif
