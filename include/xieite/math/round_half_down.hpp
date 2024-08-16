#ifndef XIEITE_HEADER_MATH_ROUND_HALF_DOWN
#	define XIEITE_HEADER_MATH_ROUND_HALF_DOWN

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_down.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfDown(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfDown(value, step) * step;
	}
}

#endif
