#ifndef XIEITE_HEADER_MATH_ALMOST_EQUAL_SLOPE
#	define XIEITE_HEADER_MATH_ALMOST_EQUAL_SLOPE

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool almostEqualSlope(const Arithmetic_ value1, const Arithmetic_ value2) noexcept {
		return std::isinf(value1) && std::isinf(value2) || xieite::math::almostEqual(value1, value2);
	}

	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool almostEqualSlope(const Arithmetic_ value1, const Arithmetic_ value2, const Arithmetic_ epsilon) noexcept {
		return std::isinf(value1) && std::isinf(value2) || xieite::math::almostEqual(value1, value2, epsilon);
	}
}

#endif
