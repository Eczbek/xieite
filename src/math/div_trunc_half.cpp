export module xieite:div_trunc_half;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_trunc_half(T left, T right) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = left / right;
			return std::floor(result) + (result < 0) + (std::fmod(std::abs(result), 1) > 0.5) * xieite::sign(result);
		} else {
			return static_cast<T>(left / right + ((left % right * xieite::sign(left)) > (right / 2 * xieite::sign(right))) * xieite::sign(left, right));
		}
	}
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
