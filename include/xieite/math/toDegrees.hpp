#ifndef XIEITE_HEADER_MATH_TODEGREES
#	define XIEITE_HEADER_MATH_TODEGREES

#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number toDegrees(const Number radians) noexcept {
		return radians * 180.0 / xieite::math::pi<Number>;
	}
}

#endif
