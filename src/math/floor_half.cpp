export module xieite:floor_half;

import :is_arith;
import :div_floor_half;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor_half(T value, T step = 1) noexcept {
		return xieite::div_floor_half(value, step) * step;
	}
}
