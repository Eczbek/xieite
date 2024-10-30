export module xieite:div_down;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_down(T dividend, std::type_identity_t<T> divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(dividend / divisor);
		} else {
			return static_cast<T>(dividend / divisor - !!(dividend % divisor) * (xieite::sign(dividend, divisor) < 0));
		}
	}
}
