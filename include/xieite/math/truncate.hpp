#ifndef DETAIL_XIEITE_HEADER_MATH_TRUNCATE
#	define DETAIL_XIEITE_HEADER_MATH_TRUNCATE
#
#	include "../math/div_truncate.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith truncate(Arith x, Arith step = 1) noexcept {
		return xieite::div_truncate(x, step) * step;
	}
}

#endif
