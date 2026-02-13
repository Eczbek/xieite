#ifndef DETAIL_XTE_HEADER_MATH_DIV_CEIL
#	define DETAIL_XTE_HEADER_MATH_DIV_CEIL
#
#	include "../math/ceil.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto div_ceil(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto quot = static_cast<Common>(x);
		if constexpr (xte::is_float<Common>) {
			return (..., (quot = xte::ceil(quot / ys)));
		} else {
			return (..., (quot = quot / static_cast<Common>(ys) + !!(quot % static_cast<Common>(ys)) * (xte::sign(quot, ys) > 0)));
		}
	};
}

#endif
