#ifndef XIEITE_HEADER_MATH_ROUND_TOWARD_ZERO
#	define XIEITE_HEADER_MATH_ROUND_TOWARD_ZERO

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_toward_zero.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundTowardZero(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideTowardZero(value, step) * step;
	}
}

#endif
