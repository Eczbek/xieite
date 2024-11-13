export module xieite:minmax;

import std;
import :is_arith;
import :intv;

export namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr xieite::intv<T> minmax(T first, Ts... rest) noexcept {
		auto result = xieite::intv<T>(first, first);
		(..., (result =
			xieite::intv<T>(
				std::min(result.start, rest),
				std::max(result.end, rest)
			)
		));
		return result;
	}
}
