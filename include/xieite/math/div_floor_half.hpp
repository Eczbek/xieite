#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR_HALF
#	define DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR_HALF
#
#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_floor_half(T dividend, T divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = dividend / divisor;
			const T fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const xieite::ssize_t quot_sign = xieite::sign(dividend, divisor);
			return static_cast<T>(dividend / divisor + ((dividend % divisor * xieite::sign(dividend)) >= (divisor / 2 * xieite::sign(divisor) + ((divisor % 2) || (quot_sign >= 0)))) * quot_sign);
		}
	}
}

#endif

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
