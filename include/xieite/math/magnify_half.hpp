#ifndef DETAIL_XIEITE_HEADER_MATH_MAGNIFY_HALF
#	define DETAIL_XIEITE_HEADER_MATH_MAGNIFY_HALF
#
#	include "../math/div_magnify_half.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith magnify_half(Arith x, Arith step = 1) noexcept {
		return xieite::div_magnify_half(x, step) * step;
	}
}

#endif
