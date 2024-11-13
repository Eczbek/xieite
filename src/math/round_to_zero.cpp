export module xieite:round_to_zero;

import :is_arith;
import :div_to_zero;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_to_zero(T value, T step = 1) noexcept {
		return xieite::div_to_zero(value, step) * step;
	}
}
