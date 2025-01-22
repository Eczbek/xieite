export module xieite:farthest;

import std;
import :diff;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Us>
	[[nodiscard]] constexpr T farthest(T target, T first, Us... rest) noexcept {
		T result = first;
		(..., (result = (xieite::diff(target, rest) > xieite::diff(target, result)) ? rest : result));
		return result;
	}
}
