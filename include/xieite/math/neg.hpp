#ifndef DETAIL_XIEITE_HEADER_MATH_NEG
#	define DETAIL_XIEITE_HEADER_MATH_NEG
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool neg(Arith x) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::signbit(x);
		} else if constexpr (!std::unsigned_integral<Arith>) {
			return x < 0;
		} else {
			return false;
		}
	}
}

#endif
