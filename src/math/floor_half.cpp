export module xieite:floor_half;

import :div_floor_half;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor_half(T n, T step = 1) noexcept {
		return xieite::div_floor_half(n, step) * step;
	}
}
