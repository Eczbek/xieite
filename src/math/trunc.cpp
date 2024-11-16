export module xieite:trunc;

import :is_arith;
import :div_trunc;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T trunc(T value, T step = 1) noexcept {
		return xieite::div_trunc(value, step) * step;
	}
}
