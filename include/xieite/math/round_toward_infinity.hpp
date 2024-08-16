#ifndef XIEITE_HEADER_MATH_ROUND_TOWARD_INFINITY
#	define XIEITE_HEADER_MATH_ROUND_TOWARD_INFINITY

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_toward_infinity.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardInfinity(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideTowardInfinity(value, step) * step;
	}
}

#endif
