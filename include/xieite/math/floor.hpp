#ifndef XIEITE_HEADER_MATH_FLOOR
#	define XIEITE_HEADER_MATH_FLOOR

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_floor.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ floor(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideFloor(value, step) * step;
	}
}

#endif
