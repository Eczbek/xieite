#ifndef XIEITE_HEADER_MATH_TODEGREES
#	define XIEITE_HEADER_MATH_TODEGREES

#	include "../concepts/Arithmetic.hpp"
#	include "../math/Result.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]]
	constexpr xieite::math::Result<Arithmetic> toDegrees(const Arithmetic radians) noexcept {
		return (radians * 180 / xieite::math::pi<Arithmetic>);
	}
}

#endif
