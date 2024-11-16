export module xieite:trunc_half;

import :is_arith;
import :div_trunc_half;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T trunc_half(T value, T step = 1) noexcept {
		return xieite::div_trunc_half(value, step) * step;
	}
}
