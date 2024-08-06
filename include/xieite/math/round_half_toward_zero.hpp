#ifndef XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_ZERO
#	define XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_ZERO

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_toward_zero.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundHalfTowardZero(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideHalfTowardZero(value, step) * step;
	}
}

#endif
