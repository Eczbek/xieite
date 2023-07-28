#ifndef XIEITE_HEADER_MATH_TORADIANS
#	define XIEITE_HEADER_MATH_TORADIANS

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
