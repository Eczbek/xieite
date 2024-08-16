#ifndef XIEITE_HEADER_MATH_ROUND_UP
#	define XIEITE_HEADER_MATH_ROUND_UP

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_up.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundUp(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideUp(value, step) * step;
	}
}

#endif
