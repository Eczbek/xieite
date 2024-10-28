export module xieite:round_half_to_zero;

import std;
import :is_arith;
import :div_half_to_zero;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_to_zero(T value, std::type_identity_t<T> step = 1) noexcept {
		return xieite::div_half_to_zero(value, step) * step;
	}
}
