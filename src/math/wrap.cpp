export module xieite:wrap;

import :is_arith;
import :minmax;
import :mod;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T wrap(T value, T limit0, T limit1) noexcept {
		const auto [min, max] = xieite::minmax(limit0, limit1);
		return xieite::mod(value - min, max - min) + min;
	}
}
