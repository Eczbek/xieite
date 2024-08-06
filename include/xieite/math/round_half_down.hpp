#ifndef XIEITE_HEADER_MATH_ROUND_HALF_DOWN
#	define XIEITE_HEADER_MATH_ROUND_HALF_DOWN

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_half_down.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundHalfDown(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideHalfDown(value, step) * step;
	}
}

#endif
