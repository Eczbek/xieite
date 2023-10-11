#ifndef XIEITE_HEADER_MATH_DIVIDE_FLOOR
#	define XIEITE_HEADER_MATH_DIVIDE_FLOOR

#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideFloor(const Integer dividend, const Integer divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) - !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}
}

#endif
