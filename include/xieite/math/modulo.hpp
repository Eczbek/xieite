#ifndef XIEITE_HEADER_MATH_MODULO
#	define XIEITE_HEADER_MATH_MODULO

#	include "../concepts/arithmetic.hpp"
#	include "../math/remainder.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic modulo(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		return xieite::math::remainder(xieite::math::remainder(dividend, divisor) + divisor * (xieite::math::sign(dividend) != xieite::math::sign(divisor)), divisor);
	}
}

#endif
