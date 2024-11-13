export module xieite:almost_eq_slope;

import std;
import :almost_eq;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, T value1) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, T value1, T epsilon) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1, epsilon);
	}
}
