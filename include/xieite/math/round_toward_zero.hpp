#ifndef XIEITE_HEADER_MATH_ROUND_TOWARD_ZERO
#	define XIEITE_HEADER_MATH_ROUND_TOWARD_ZERO

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_toward_zero.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardZero(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideTowardZero(value, step) * step;
	}
}

#endif
