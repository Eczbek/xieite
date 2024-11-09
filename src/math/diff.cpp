export module xieite:diff;

import std;
import :is_arith;
import :try_unsign;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsign<T> diff(T value0, std::type_identity_t<T> value1) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(value0 - value1);
		} else {
			using Result = xieite::try_unsign<T>;
			return (value0 > value1)
				? (static_cast<Result>(value0) - static_cast<Result>(value1))
				: (static_cast<Result>(value1) - static_cast<Result>(value0));
		}
	}
}
