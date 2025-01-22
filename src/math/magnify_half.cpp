export module xieite:magnify_half;

import :div_magnify_half;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify_half(T n, T step = 1) noexcept {
		return xieite::div_magnify_half(n, step) * step;
	}
}
