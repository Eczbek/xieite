#ifndef XIEITE_HEADER_MATH_DIVIDE_DOWN
#	define XIEITE_HEADER_MATH_DIVIDE_DOWN

#	include <cmath>
#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic divideDown(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::floor(dividend / divisor);
		} else {
			return static_cast<Arithmetic>(dividend / divisor - !!(dividend % divisor) * (xieite::math::sign(dividend, divisor) < 0));
		}
	}
}

#endif
