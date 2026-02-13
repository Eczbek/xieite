#ifndef DETAIL_XTE_HEADER_MATH_REM_CHECKED
#	define DETAIL_XTE_HEADER_MATH_REM_CHECKED
#
#	include "../data/null.hpp"
#	include "../data/opt.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/rem.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_signed.hpp"
#	include <limits>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto rem_checked(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		if constexpr (using Common = std::common_type_t<decltype(x), decltype(ys)...>; xte::is_signed<Common>) {
			if (sizeof...(ys) && (x == std::numeric_limits<Common>::lowest()) && (ys...[0] == -1)) {
				return xte::null;
			}
		}
		if ((... && static_cast<bool>(ys))) {
			if (auto rem = xte::rem(x, ys...); xte::is_finite(rem)) {
				return xte::opt(rem);
			}
		}
		return xte::null;
	};
}

#endif
