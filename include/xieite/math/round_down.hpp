#ifndef XIEITE_HEADER_MATH_ROUND_DOWN
#	define XIEITE_HEADER_MATH_ROUND_DOWN

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/ceiling.hpp"
#	include "../math/floor.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number roundDown(const Number value, const Number step = 1) noexcept {
		return xieite::math::isNegative(value) ? xieite::math::ceiling(value, step) : xieite::math::floor(value, step);
	}
}

#endif
