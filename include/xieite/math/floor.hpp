#ifndef XIEITE_HEADER_MATH_FLOOR
#	define XIEITE_HEADER_MATH_FLOOR

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_floor.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number floor(const Number value, const Number step = 1) noexcept {
		return xieite::math::divideFloor(value, step) * step;
	}
}

#endif
