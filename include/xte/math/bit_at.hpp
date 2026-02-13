#ifndef DETAIL_XTE_HEADER_MATH_BIT_AT
#	define DETAIL_XTE_HEADER_MATH_BIT_AT
#
#	include "../math/rshift.hpp"
#	include "../trait/is_int.hpp"
#	include "../util/types.hpp"

namespace xte {
	[[nodiscard]] constexpr bool bit_at(xte::is_int auto x, xte::uz pos) noexcept {
		return xte::rshift(x, pos) & 1;
	};
}

#endif
