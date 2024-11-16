export module xieite:floor;

import :is_arith;
import :div_floor;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor(T value, T step = 1) noexcept {
		return xieite::div_floor(value, step) * step;
	}
}
