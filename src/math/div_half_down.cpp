export module xieite:div_half_down;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_half_down(T dividend, T divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = dividend / divisor;
			const T fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const int quot_sign = xieite::sign(dividend, divisor);
			return static_cast<T>(dividend / divisor + ((dividend % divisor * xieite::sign(dividend)) >= (divisor / 2 * xieite::sign(divisor) + ((divisor % 2) || (quot_sign >= 0)))) * quot_sign);
		}
	}
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
