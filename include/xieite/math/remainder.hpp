#ifndef XIEITE_HEADER_MATH_REMAINDER
#	define XIEITE_HEADER_MATH_REMAINDER

#	include <cmath>
#	include <concepts>

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ remainder(const Integral_ dividend, const Integral_ divisor) noexcept {
		return dividend % divisor;
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ remainder(const Fractional_ dividend, const Fractional_ divisor) noexcept {
		return std::fmod(dividend, divisor);
	}
}

#endif
