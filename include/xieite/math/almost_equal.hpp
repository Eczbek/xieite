#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic value1, const Arithmetic value2) noexcept {
		if constexpr (std::integral<Arithmetic>) {
			return value1 == value2;
		} else {
			const Arithmetic scale = std::abs(value1) + std::abs(value2);
			return std::abs(value1 - value2) <= (std::numeric_limits<Arithmetic>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic value1, const Arithmetic value2, const Arithmetic epsilon) noexcept {
		if constexpr (std::integral<Arithmetic>) {
			return xieite::math::difference(value1, value2) <= xieite::math::absolute(epsilon);
		} else {
			return std::abs(value1 - value2) <= std::abs(epsilon);
		}
	}
}

#endif
