export module xieite:div_to_zero;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_to_zero(T dividend, std::type_identity_t<T> divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(dividend / divisor) + ((dividend < 0) != (divisor < 0));
		} else {
			return dividend / divisor;
		}
	}
}
