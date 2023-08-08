#ifndef XIEITE_HEADER__MATH__DIVIDE_CEILING
#	define XIEITE_HEADER__MATH__DIVIDE_CEILING

#	include <concepts>
#	include "../math/divideDown.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	constexpr Integer divideCeiling(const Integer dividend, const Integer divisor) noexcept {
		return (xieite::math::divideDown(dividend, divisor) + !!(dividend % divisor) * (xieite::math::sign(dividend) == xieite::math::sign(divisor));
	}
}

#endif
