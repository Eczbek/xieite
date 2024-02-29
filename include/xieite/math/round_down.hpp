#ifndef XIEITE_HEADER_MATH_ROUND_DOWN
#	define XIEITE_HEADER_MATH_ROUND_DOWN

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/ceiling.hpp"
#	include "../math/floor.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2 = Number1>
	[[nodiscard]] constexpr std::common_type_t<Number1, Number2> roundDown(const Number1 value, const Number2 step = 1) noexcept {
		return xieite::math::isNegative(value) ? xieite::math::ceiling(value, step) : xieite::math::floor(value, step);
	}
}

#endif
