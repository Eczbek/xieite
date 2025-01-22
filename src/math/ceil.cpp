export module xieite:ceil;

import :div_ceil;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T ceil(T n, T step = 1) noexcept {
		return xieite::div_ceil(n, step) * step;
	}
}
