export module xieite:trunc_half;

import :div_trunc_half;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T trunc_half(T n, T step = 1) noexcept {
		return xieite::div_trunc_half(n, step) * step;
	}
}
