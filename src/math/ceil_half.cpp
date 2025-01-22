export module xieite:ceil_half;

import :div_ceil_half;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T ceil_half(T n, T step = 1) noexcept {
		return xieite::div_ceil_half(n, step) * step;
	}
}
