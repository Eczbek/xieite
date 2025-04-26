#ifndef DETAIL_XIEITE_HEADER_MATH_MAGNIFY
#	define DETAIL_XIEITE_HEADER_MATH_MAGNIFY
#
#	include "../math/div_magnify.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith magnify(Arith x, Arith step = 1) noexcept {
		return xieite::div_magnify(x, step) * step;
	}
}

#endif
