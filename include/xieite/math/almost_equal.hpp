#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool almostEqual(const Number value1, const Number value2) noexcept {
		if constexpr (std::integral<Number>) {
			return value1 == value2;
		} else {
			return std::abs(value1 - value2) <= std::numeric_limits<Number>::epsilon();
		}
	}
}

#endif
