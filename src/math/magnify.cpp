export module xieite:magnify;

import :is_arith;
import :div_magnify;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify(T value, T step = 1) noexcept {
		return xieite::div_magnify(value, step) * step;
	}
}
