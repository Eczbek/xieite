#ifndef XIEITE_HEADER__MATH__TO_DEGREES
#	define XIEITE_HEADER__MATH__TO_DEGREES

#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr xieite::math::Result<Arithmetic> toDegrees(const Arithmetic radians) noexcept {
		return radians * 180 / xieite::math::pi<Arithmetic>;
	}
}

#endif
