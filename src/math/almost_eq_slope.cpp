export module xieite:almost_eq_slope;

import std;
import :almost_eq;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T val1, std::type_identity_t<T> val2) noexcept {
		return (std::isinf(val1) && std::isinf(val2)) || xieite::almost_eq(val1, val2);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T val1, std::type_identity_t<T> val2, std::type_identity_t<T> epsilon) noexcept {
		return (std::isinf(val1) && std::isinf(val2)) || xieite::almost_eq(val1, val2, epsilon);
	}
}
