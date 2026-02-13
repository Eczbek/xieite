#ifndef DETAIL_XTE_HEADER_MATH_DIV_CHECKED
#	define DETAIL_XTE_HEADER_MATH_DIV_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/div.hpp"
#	include "../math/is_finite.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_signed.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_checked(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		bool overflow = false;
		if constexpr (using Common = std::common_type_t<decltype(x), decltype(ys)...>; xte::is_signed<Common>) {
			(void)(... && ((overflow = !ys || (ys == -(x == std::numeric_limits<Common>::lowest()))), ys == 1));
		} else {
			overflow = (!xte::is_finite(x) || ... || (!xte::is_finite(ys) || !static_cast<bool>(ys)));
		}
		return overflow ? xte::null : xte::opt(xte::div(x, ys...));
	};
}

#endif
