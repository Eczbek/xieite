export module xieite:math.div_to_inf;

import std;
import :is_arith;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T div_to_inf(T dividend, std::type_identity_t<T> divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::ceil(dividend / divisor) - ((dividend < 0) != (divisor < 0));
		} else {
			return static_cast<T>(dividend / divisor + !!(dividend % divisor) * xieite::sign(dividend, divisor));
		}
	}
}
