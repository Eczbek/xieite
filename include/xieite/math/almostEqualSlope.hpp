#ifndef XIEITE_HEADER_MATH_ALMOSTEQUALSLOPE
#	define XIEITE_HEADER_MATH_ALMOSTEQUALSLOPE

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/almostEqual.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr bool almostEqualSlope(const Number value1, const Number value2) noexcept {
		return (std::isinf(value1) && std::isinf(value2)) || xieite::math::almostEqual(value1, value2);
	}
}

#endif
