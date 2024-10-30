export module xieite:almost_eq;

import std;
import :abs;
import :diff;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T val1, std::type_identity_t<T> val2) noexcept {
		if constexpr (std::floating_point<T>) {
			const T scale = std::abs(val1) + std::abs(val2);
			// To account for precision loss, take reciprocal of `scale` if it is less than 1
			return std::abs(val1 - val2) <= (std::numeric_limits<T>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return val1 == val2;
		}
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T val1, std::type_identity_t<T> val2, std::type_identity_t<T> epsilon) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(val1 - val2) <= std::abs(epsilon);
		} else {
			return xieite::diff(val1, val2) <= xieite::abs(epsilon);
		}
	}
}
