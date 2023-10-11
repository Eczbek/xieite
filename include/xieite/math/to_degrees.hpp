#ifndef XIEITE_HEADER_MATH_TO_DEGREES
#	define XIEITE_HEADER_MATH_TO_DEGREES

#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> toDegrees(const Number radians) noexcept {
		return radians * 180 / xieite::math::pi<xieite::math::Result<Number>>;
	}
}

#endif
