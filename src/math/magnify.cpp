export module xieite:magnify;

import :div_magnify;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify(T n, T step = 1) noexcept {
		return xieite::div_magnify(n, step) * step;
	}
}
