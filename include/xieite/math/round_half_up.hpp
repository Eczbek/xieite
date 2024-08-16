#ifndef XIEITE_HEADER_MATH_ROUND_HALF_UP
#	define XIEITE_HEADER_MATH_ROUND_HALF_UP

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_up.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfUp(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfUp(value, step) * step;
	}
}

#endif
