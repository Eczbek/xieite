#ifndef XIEITE_HEADER_MATH_REMAINDER
#	define XIEITE_HEADER_MATH_REMAINDER

#	include <cmath>
#	include <concepts>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr Integral remainder(const Integral dividend, const Integral divisor) noexcept {
		return dividend % divisor;
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional remainder(const Fractional dividend, const Fractional divisor) noexcept {
		return std::fmod(dividend, divisor);
	}
}

#endif
