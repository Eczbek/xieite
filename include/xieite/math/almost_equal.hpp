#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic_ value1, const Arithmetic_ value2) noexcept {
		if constexpr (std::integral<Arithmetic_>) {
			return value1 == value2;
		} else {
			return std::abs(value1 - value2) <= std::numeric_limits<Arithmetic_>::epsilon();
		}
	}
}

#endif
