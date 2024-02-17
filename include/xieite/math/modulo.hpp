#ifndef XIEITE_HEADER_MATH_MODULO
#	define XIEITE_HEADER_MATH_MODULO

#	include "../concepts/arithmetic.hpp"
#	include "../math/remainder.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number modulo(const Number dividend, const Number divisor) noexcept {
		return xieite::math::remainder(xieite::math::remainder(dividend, divisor) + divisor * (xieite::math::sign(dividend) != xieite::math::sign(divisor)), divisor);
	}
}

#endif
