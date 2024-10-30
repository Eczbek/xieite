export module xieite:round_down;

import std;
import :is_arith;
import :div_down;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_down(T value, std::type_identity_t<T> step = 1) noexcept {
		return xieite::div_down(value, step) * step;
	}
}
