#ifndef DETAIL_XIEITE_HEADER_MATH_CEIL
#	define DETAIL_XIEITE_HEADER_MATH_CEIL
#
#	include "../math/div_ceil.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T ceil(T n, T step = 1) noexcept {
		return xieite::div_ceil(n, step) * step;
	}
}

#endif
