#ifndef DETAIL_XIEITE_HEADER_MATH_CEIL_HALF
#	define DETAIL_XIEITE_HEADER_MATH_CEIL_HALF
#
#	include "../math/div_ceil_half.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith ceil_half(Arith x, Arith step = 1) noexcept {
		return xieite::div_ceil_half(x, step) * step;
	}
}

#endif
