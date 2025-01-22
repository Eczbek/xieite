export module xieite:floor;

import :div_floor;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor(T n, T step = 1) noexcept {
		return xieite::div_floor(n, step) * step;
	}
}
