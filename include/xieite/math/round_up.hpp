#ifndef XIEITE_HEADER_MATH_ROUND_UP
#	define XIEITE_HEADER_MATH_ROUND_UP

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/ceiling.hpp"
#	include "../math/floor.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundUp(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::isNegative(value) ? xieite::math::floor(value, step) : xieite::math::ceiling(value, step);
	}
}

#endif
