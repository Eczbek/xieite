export module xieite:farthest;

import std;
import :is_arith;
import :diff;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T farthest(T target, std::type_identity_t<T> val1, std::type_identity_t<T> val2) noexcept {
		return (xieite::diff(target, val1) > xieite::diff(target, val2)) ? val1 : val2;
	}
}
