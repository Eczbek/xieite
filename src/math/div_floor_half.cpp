export module xieite:div_floor_half;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_floor_half(T left, T right) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = left / right;
			const T fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const int quot_sign = xieite::sign(left, right);
			return static_cast<T>(left / right + ((left % right * xieite::sign(left)) >= (right / 2 * xieite::sign(right) + ((right % 2) || (quot_sign >= 0)))) * quot_sign);
		}
	}
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
