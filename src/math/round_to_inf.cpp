export module xieite:round_to_inf;

import :is_arith;
import :div_to_inf;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_to_inf(T value, T step = 1) noexcept {
		return xieite::div_to_inf(value, step) * step;
	}
}
