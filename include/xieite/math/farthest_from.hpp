#ifndef XIEITE_HEADER_MATH_FARTHEST_FROM
#	define XIEITE_HEADER_MATH_FARTHEST_FROM

#	include "../concepts/arithmetic.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic& farthestFrom(const Arithmetic target, Arithmetic& value1, Arithmetic& value2) noexcept {
		return (xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic farthestFrom(const Arithmetic target, const Arithmetic& value1, const Arithmetic& value2) noexcept {
		Arithmetic copy1 = value1;
		Arithmetic copy2 = value2;
		return xieite::math::farthestFrom(target, copy1, copy2);
	}
}

#endif
