#ifndef DETAIL_XIEITE_HEADER_MATH_REM
#	define DETAIL_XIEITE_HEADER_MATH_REM
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith rem(Arith lhs, Arith rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::fmod(lhs, rhs);
		} else {
			return lhs % rhs;
		}
	}
}

#endif
