#ifndef XIEITE_HEADER_MATH_IS_BETWEEN_FIXED
#	define XIEITE_HEADER_MATH_IS_BETWEEN_FIXED

#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenFixed(const Arithmetic value, const Arithmetic limit1, const Arithmetic limit2, const bool floorInclusive = true, const bool ceilingInclusive = true) noexcept {
		return (floorInclusive ? (value >= limit1) : (value > limit1)) && (ceilingInclusive ? (value <= limit2) : (value < limit2)) || (floorInclusive ? (value >= limit2) : (value > limit2)) && (ceilingInclusive ? (value <= limit1) : (value < limit1));
	}
}

#endif
