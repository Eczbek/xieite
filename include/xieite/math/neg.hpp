#ifndef DETAIL_XIEITE_HEADER_MATH_NEG
#	define DETAIL_XIEITE_HEADER_MATH_NEG
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool neg(T n) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::signbit(n);
		} else if constexpr (!std::unsigned_integral<T>) {
			return n < 0;
		} else {
			return false;
		}
	}
}

#endif
