export module xieite:div_ceil;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_ceil(T dividend, T divisor) {
		if constexpr (std::floating_point<T>) {
			return std::ceil(dividend / divisor);
		} else {
			return static_cast<T>(dividend / divisor + !!(dividend % divisor) * (xieite::sign(dividend, divisor) > 0));
		}
	}
}
