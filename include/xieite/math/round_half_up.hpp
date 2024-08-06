#ifndef XIEITE_HEADER_MATH_ROUND_HALF_UP
#	define XIEITE_HEADER_MATH_ROUND_HALF_UP

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_up.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundHalfUp(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideHalfUp(value, step) * step;
	}
}

#endif
