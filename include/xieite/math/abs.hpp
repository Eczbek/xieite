#ifndef DETAIL_XIEITE_HEADER_MATH_ABS
#	define DETAIL_XIEITE_HEADER_MATH_ABS
#
#	include <cmath>
#	include <concepts>
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr xieite::try_unsigned<Arith> abs(Arith x) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::abs(x);
		} else if constexpr (std::unsigned_integral<Arith>) {
			return x;
		} else {
			return (x < 0)
				? -static_cast<xieite::try_unsigned<Arith>>(x)
				: static_cast<xieite::try_unsigned<Arith>>(x);
		}
	}
}

#endif

// Making the return type `auto` allows the negated value to promote
