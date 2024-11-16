export module xieite:div_trunc;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_trunc(T left, T right) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(left / right) + ((left < 0) != (right < 0));
		} else {
			return left / right;
		}
	}
}
