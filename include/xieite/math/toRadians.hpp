#ifndef XIEITE_HEADER__MATH__TO_RADIANS
#	define XIEITE_HEADER__MATH__TO_RADIANS

#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> toRadians(const Arithmetic degrees) noexcept {
		return (degrees * xieite::math::pi<Arithmetic> / 180);
	}
}

#endif
