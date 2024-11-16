export module xieite:magnify_half;

import :is_arith;
import :div_magnify_half;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify_half(T value, T step = 1) noexcept {
		return xieite::div_magnify_half(value, step) * step;
	}
}
