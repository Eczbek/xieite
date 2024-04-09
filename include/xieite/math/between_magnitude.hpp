#ifndef XIEITE_HEADER_MATH_BETWEEN_MAGNITUDE
#	define XIEITE_HEADER_MATH_BETWEEN_MAGNITUDE

#	include "../concepts/arithmetic.hpp"
#	include "../math/closest_to.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool betweenMagnitude(const Number value, const Number limit1, const Number limit2, const bool downInclusive = true, const bool upInclusive = true) noexcept {
		const Number down = xieite::math::closestTo(0, limit1, limit2);
		const Number up = (down == limit1) ? limit2 : limit1;
		return (downInclusive ? (value >= down) : (value > down)) && (upInclusive ? (value <= up) : (value < up)) || (downInclusive ? (value <= down) : (value < down)) && (upInclusive ? (value >= up) : (value > up));
	}
}

#endif
