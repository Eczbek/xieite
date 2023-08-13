#ifndef XIEITE_HEADER__MATH__ALMOST_EQUAL_SLOPE
#	define XIEITE_HEADER__MATH__ALMOST_EQUAL_SLOPE

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
	constexpr bool almostEqualSlope(const Arithmetic1 value1, const Arithmetic2 value2) noexcept {
		return std::isinf(value1) && std::isinf(value2) || xieite::math::almostEqual(value1, value2);
	}
}

#endif
