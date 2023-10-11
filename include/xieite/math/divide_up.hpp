#ifndef XIEITE_HEADER_MATH_DIVIDE_UP
#	define XIEITE_HEADER_MATH_DIVIDE_UP

#	include <concepts>
#	include "../math/divide_down.hpp"
#	include "../math/sign.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideUp(const Integer dividend, const Integer divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) - !!(dividend % divisor) * xieite::math::splitBoolean(xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
