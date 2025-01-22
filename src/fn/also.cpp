module;

#include <xieite/fn.hpp>
#include <xieite/fwd.hpp>

export module xieite:also;

import std;
import :has_cp_ctor;
import :has_noex_cp_ctor;
import :is_noex_invoc;

export namespace xieite {
	template<xieite::has_cp_ctor T, std::invocable<T&&> F>
	[[nodiscard]] constexpr T also(T&& x, F&& fn = {})
	noexcept(xieite::has_noex_cp_ctor<T> && xieite::is_noex_invoc<F, void(T&&)>) {
		const T copy = x;
		std::invoke(XIEITE_FWD(fn), x);
		return copy;
	}

	template<xieite::has_cp_ctor T, std::invocable<> F>
	[[nodiscard]] constexpr T also(T&& x, F&& fn = {})
	noexcept(xieite::has_noex_cp_ctor<T> && xieite::is_noex_invoc<F>) {
		return xieite::also(XIEITE_FWD(x), XIEITE_FN_LOCAL(std::invoke(XIEITE_FWD(fn))));
	}
}
