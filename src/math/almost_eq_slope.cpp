export module xieite:almost_eq_slope;

import std;
import :almost_eq;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T n, T m) noexcept {
		return (std::isinf(n) && std::isinf(m)) || xieite::almost_eq(n, m);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T n, T m, T epsilon) noexcept {
		return (std::isinf(n) && std::isinf(m)) || xieite::almost_eq(n, m, epsilon);
	}
}
