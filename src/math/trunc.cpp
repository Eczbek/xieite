export module xieite:trunc;

import :div_trunc;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T trunc(T n, T step = 1) noexcept {
		return xieite::div_trunc(n, step) * step;
	}
}
