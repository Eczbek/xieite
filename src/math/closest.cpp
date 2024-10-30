export module xieite:closest;

import std;
import :is_arith;
import :diff;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T closest(T target, std::type_identity_t<T> val1, std::type_identity_t<T> val2) noexcept {
		return (xieite::diff(target, val1) > xieite::diff(target, val2)) ? val2 : val1;
	}
}
