#ifndef XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_ROUND_HALF_TOWARD_INFINITY

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_toward_infinity"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundHalfTowardInfinity(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideHalfTowardInfinity(value, step) * step;
	}
}

#endif
