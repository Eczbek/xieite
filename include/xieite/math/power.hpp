#ifndef XIEITE_HEADER_MATH_POWER
#	define XIEITE_HEADER_MATH_POWER

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ power(Integral_ base, std::size_t exponent) noexcept {
		Integral_ result = 1;
		while (exponent) {
			if (exponent & 1) {
				result *= base;
			}
			exponent >>= 1;
			base *= base;
		}
		return result;
	}
}

#endif
