#ifndef DETAIL_XTE_HEADER_MATH_DIV_CEIL_HALF
#	define DETAIL_XTE_HEADER_MATH_DIV_CEIL_HALF
#
#	include "../math/floor.hpp"
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_ceil_half(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto quot = static_cast<Common>(x);
		if constexpr (xte::is_float<Common>) {
			Common fraction;
			return (..., (fraction = xte::rem(quot /= ys, 1), quot = xte::floor(quot) + (quot < 0) + (fraction >= 0.5) - (fraction < -0.5)));
		} else {
			xte::iz sign;
			return (..., (sign = xte::sign(quot, ys), quot = static_cast<Common>(quot / static_cast<Common>(ys) + sign * ((quot % static_cast<Common>(ys) * xte::sign(quot)) >= (ys / 2 * xte::sign(ys) + ((ys % 2) || (sign < 0)))))));
		}
	};
}

#endif
