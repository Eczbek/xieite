#ifndef XIEITE_HEADER_MATH_ROUND_DOWN
#	define XIEITE_HEADER_MATH_ROUND_DOWN

#	include "../concepts/arithmetic.hpp"
#	include "../math/divide_down.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundDown(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::divideDown(value, step) * step;
	}
}

#endif
