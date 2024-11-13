export module xieite:mod;

import std;
import :is_arith;
import :rem;
import :sign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T mod(T dividend, T divisor) noexcept {
		return xieite::rem(xieite::rem(dividend, divisor) + divisor * (xieite::sign(dividend) != xieite::sign(divisor)), divisor);
	}
}
