#ifndef DETAIL_XIEITE_HEADER_MATH_CEIL
#	define DETAIL_XIEITE_HEADER_MATH_CEIL
#
#	include "../math/div_ceil.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith ceil(Arith x, Arith step = 1) noexcept {
		return xieite::div_ceil(x, step) * step;
	}
}

#endif
