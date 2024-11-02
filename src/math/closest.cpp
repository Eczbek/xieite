export module xieite:closest;

import std;
import :is_arith;
import :diff;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T closest(T target, std::type_identity_t<T> value0, std::type_identity_t<T> value1) noexcept {
		return (xieite::diff(target, value0) > xieite::diff(target, value1)) ? value1 : value0;
	}
}
