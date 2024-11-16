export module xieite:ceil_half;

import :is_arith;
import :div_ceil_half;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T ceil_half(T value, T step = 1) noexcept {
		return xieite::div_ceil_half(value, step) * step;
	}
}
