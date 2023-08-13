#ifndef XIEITE_HEADER__MATH__DIVIDE_UP
#	define XIEITE_HEADER__MATH__DIVIDE_UP

#	include <concepts>
#	include "../math/divideDown.hpp"
#	include "../math/sign.hpp"
#	include "../math/splitBoolean.hpp"

namespace xieite::math {
	template<std::integral Integer>
	constexpr Integer divideUp(const Integer dividend, const Integer divisor) noexcept {
		return xieite::math::divideDown(dividend, divisor) - !!(dividend % divisor) * xieite::math::splitBoolean(xieite::math::sign(dividend) != xieite::math::sign(divisor));
	}
}

#endif
