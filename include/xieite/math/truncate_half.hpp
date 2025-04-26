#ifndef DETAIL_XIEITE_HEADER_MATH_TRUNCATE_HALF
#	define DETAIL_XIEITE_HEADER_MATH_TRUNCATE_HALF
#
#	include "../math/div_truncate_half.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith truncate_half(Arith x, Arith step = 1) noexcept {
		return xieite::div_truncate_half(x, step) * step;
	}
}

#endif
