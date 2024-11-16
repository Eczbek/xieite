export module xieite:ceil;

import :is_arith;
import :div_ceil;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T ceil(T value, T step = 1) noexcept {
		return xieite::div_ceil(value, step) * step;
	}
}
