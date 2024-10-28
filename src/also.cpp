module;

#include <xieite/fn.hpp>
#include <xieite/fwd.hpp>

export module xieite:also;

import std;
import :is_copy_ctor;

export namespace xieite {
	template<xieite::is_copy_ctor T, std::invocable<T&&> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn)
	noexcept(std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_invocable_v<F, T&&>) {
		const T copy = value;
		std::invoke(XIEITE_FWD(fn), value);
		return copy;
	}

	template<xieite::is_copy_ctor T, std::invocable<> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn)
	noexcept(std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_invocable_v<F>) {
		return xieite::also(XIEITE_FWD(value), XIEITE_FN(std::invoke(XIEITE_FWD($0))));
	}
}
