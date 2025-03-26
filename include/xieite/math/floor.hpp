#ifndef DETAIL_XIEITE_HEADER_MATH_FLOOR
#	define DETAIL_XIEITE_HEADER_MATH_FLOOR
#
#	include "../math/div_floor.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor(T n, T step = 1) noexcept {
		return xieite::div_floor(n, step) * step;
	}
}

#endif
