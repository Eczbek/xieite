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
		using common_type = std::common_type_t<decltype(x), decltype(ys)...>;
		auto quot = static_cast<common_type>(x);
		if constexpr (xte::is_float<common_type>) {
			return (..., (quot = xte::ceil(quot / ys)));
		} else {
			return (..., (quot = quot / static_cast<common_type>(ys) + !!(quot % static_cast<common_type>(ys)) * (xte::sign(quot, ys) > 0)));
		}
	};
}

#endif
