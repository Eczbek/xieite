export module xieite:div_ceil;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_ceil(T left, T right) {
		if constexpr (std::floating_point<T>) {
			return std::ceil(left / right);
		} else {
			return static_cast<T>(left / right + !!(left % right) * (xieite::sign(left, right) > 0));
		}
	}
}
