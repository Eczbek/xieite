#ifndef XIEITE_HEADER__MATH__TO_DEGREES
#	define XIEITE_HEADER__MATH__TO_DEGREES

#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> toDegrees(const Number radians) noexcept {
		return radians * 180 / xieite::math::pi<xieite::math::Result<Number>>;
	}
}

#endif
