module;

#include <xieite/fn.hpp>
#include <xieite/fwd.hpp>

export module xieite:also;

import std;
import :is_cp_ctor;
import :is_invoc;
import :is_nothrow_cp_ctor;
import :is_nothrow_invoc;

export namespace xieite {
	template<xieite::is_cp_ctor T, std::is_invoc<void(T&&)> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn = {})
	noexcept(xieite::is_nothrow_cp_ctor<T> && xieite::is_nothrow_invoc<F, void(T&&)>) {
		const T copy = value;
		std::invoke(XIEITE_FWD(fn), value);
		return copy;
	}

	template<xieite::is_cp_ctor T, std::is_invoc<> F>
	[[nodiscard]] constexpr T also(T&& value, F&& fn = {})
	noexcept(xieite::is_nothrow_cp_ctor<T> && xieite::is_nothrow_invoc<F>) {
		return xieite::also(XIEITE_FWD(value), XIEITE_FN(std::invoke(XIEITE_FWD($0))));
	}
}
