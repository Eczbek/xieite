#ifndef XIEITE_HEADER_MATH_ROUND_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_ROUND_TOWARD_INFINITY

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_toward_infinity.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundTowardInfinity(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideTowardInfinity(value, step) * step;
	}
}

#endif
