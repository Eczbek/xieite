#ifndef XIEITE_HEADER_MATH_TO_RADIANS
#	define XIEITE_HEADER_MATH_TO_RADIANS

#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> toRadians(const Number degrees) noexcept {
		return degrees * xieite::math::pi<xieite::math::Result<Number>> / 180;
	}
}

#endif