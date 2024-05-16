#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic_ value1, const Arithmetic_ value2) noexcept {
		if constexpr (std::integral<Arithmetic_>) {
			return value1 == value2;
		} else {
			const Arithmetic_ scale = std::abs(value1) + std::abs(value2);
			return std::abs(value1 - value2) <= (std::numeric_limits<Arithmetic_>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic_ value1, const Arithmetic_ value2, const Arithmetic_ epsilon) noexcept {
		if constexpr (std::integral<Arithmetic_>) {
			return xieite::math::difference(value1, value2) <= xieite::math::absolute(epsilon);
		} else {
			return std::abs(value1 - value2) <= std::abs(epsilon);
		}
	}
}

#endif
