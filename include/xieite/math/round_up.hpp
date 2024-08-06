#ifndef XIEITE_HEADER_MATH_ROUND_UP
#	define XIEITE_HEADER_MATH_ROUND_UP

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_up.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundUp(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideUp(value, step) * step;
	}
}

#endif
