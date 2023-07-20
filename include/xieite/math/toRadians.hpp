#ifndef XIEITE_HEADER_MATH_TORADIANS
#	define XIEITE_HEADER_MATH_TORADIANS

#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>
#	include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr xieite::math::Result<Number> toRadians(const Number degrees) noexcept {
		return degrees * xieite::math::pi<Number> / 180.0;
	}
}

#endif
