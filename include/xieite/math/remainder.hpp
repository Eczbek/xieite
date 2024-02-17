#ifndef XIEITE_HEADER_MATH_REMAINDER
#	define XIEITE_HEADER_MATH_REMAINDER

#	include <cmath>
#	include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer remainder(const Integer dividend, const Integer divisor) noexcept {
		return dividend % divisor;
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint remainder(const FloatingPoint dividend, const FloatingPoint divisor) noexcept {
		return std::fmod(dividend, divisor);
	}
}

#endif
