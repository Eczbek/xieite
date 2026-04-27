#ifndef DETAIL_XTE_HEADER_MATH_MOD_CHECKED
#	define DETAIL_XTE_HEADER_MATH_MOD_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr auto mod_checked(xte::is_number auto dividend, xte::is_number auto... divisors) noexcept {
		return (!xte::is_finite(dividend) || ... || (!xte::is_finite(dividend) || xte::approx_equal(divisors, 0)))
			? xte::null
			: xte::opt(xte::mod(dividend, divisors...));
	};
}

#endif
