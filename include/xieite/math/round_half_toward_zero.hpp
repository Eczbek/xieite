#ifndef XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_ZERO
#	define XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_ZERO

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_toward_zero.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfTowardZero(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfTowardZero(value, step) * step;
	}
}

#endif
