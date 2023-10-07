#ifndef XIEITE_HEADER__MATH__ALMOST_EQUAL_SLOPE
#	define XIEITE_HEADER__MATH__ALMOST_EQUAL_SLOPE

#	include <cmath>
#	include "../concepts/Numeric.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	[[nodiscard]] constexpr bool almostEqualSlope(const Number1 value1, const Number2 value2) noexcept {
		return std::isinf(value1) && std::isinf(value2) || xieite::math::almostEqual(value1, value2);
	}
}

#endif
