export module xieite:diff;

import std;
import :is_arith;
import :try_unsigned;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsigned<T> diff(T val1, std::type_identity_t<T> val2) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(val1 - val2);
		} else {
			using Result = xieite::try_unsigned<T>;
			return (val1 > val2)
				? (static_cast<Result>(val1) - static_cast<Result>(val2))
				: (static_cast<Result>(val2) - static_cast<Result>(val1));
		}
	}
}
