#ifndef XIEITE_HEADER_MATH_ROUND_DOWN
#	define XIEITE_HEADER_MATH_ROUND_DOWN

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/ceiling.hpp"
#	include "../math/floor.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ roundDown(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return xieite::math::isNegative(value) ? xieite::math::ceiling(value, step) : xieite::math::floor(value, step);
	}
}

#endif
