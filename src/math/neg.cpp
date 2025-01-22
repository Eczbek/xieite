export module xieite:neg;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool neg(T n) noexcept {
		if constexpr (!std::unsigned_integral<T>) {
			return n < 0;
		} else {
			return false;
		}
	}
}
