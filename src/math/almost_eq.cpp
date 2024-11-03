export module xieite:almost_eq;

import std;
import :abs;
import :diff;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T value0, std::type_identity_t<T> value1) noexcept {
		if constexpr (std::floating_point<T>) {
			const T scale = std::abs(value0) + std::abs(value1);
			// To account for precision loss, take reciprocal of `scale` if it is less than 1
			return std::abs(value0 - value1) <= (std::numeric_limits<T>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return value0 == value1;
		}
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T value0, std::type_identity_t<T> value1, std::type_identity_t<T> epsilon) noexcept {
		return xieite::diff(value0, value1) <= xieite::abs(epsilon);
	}
}
