export module xieite:round_half_down;

import std;
import :is_arith;
import :div_half_down;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_down(T value, std::type_identity_t<T> step = 1) noexcept {
		return xieite::div_half_down(value, step) * step;
	}
}
