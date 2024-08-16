#ifndef XIEITE_HEADER_MATH_ROUND_DOWN
#	define XIEITE_HEADER_MATH_ROUND_DOWN

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_down.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundDown(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideDown(value, step) * step;
	}
}

#endif
