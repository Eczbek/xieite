#ifndef DETAIL_XTE_HEADER_MATH_MINMAX
#	define DETAIL_XTE_HEADER_MATH_MINMAX
#
#	include "../data/fixed_array.hpp"
#	include "../math/max.hpp"
#	include "../math/min.hpp"
#	include "../trait/is_number.hpp"

namespace xte {
	[[nodiscard]] constexpr auto minmax(xte::is_number auto x, xte::is_number auto y) noexcept {
		return xte::fixed_array { xte::min(x, y), xte::max(x, y) };
	};
}

#endif
