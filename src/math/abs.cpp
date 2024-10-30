export module xieite:abs;

import std;
import :is_arith;
import :neg;
import :try_unsigned;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsigned<T> abs(T value) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(value);
		} else {
			return xieite::neg(value)
				? -static_cast<xieite::try_unsigned<T>>(value)
				: static_cast<xieite::try_unsigned<T>>(value);
		}
	}
}
