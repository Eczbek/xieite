export module xieite:round_up;

import :is_arith;
import :div_up;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_up(T value, T step = 1) noexcept {
		return xieite::div_up(value, step) * step;
	}
}
