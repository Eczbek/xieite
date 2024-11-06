module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:any_true;

import std;

export namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr auto any_true(F&& fn, Args&&... args)
	XIEITE_ARROW(... || std::invoke_r<bool>(fn, XIEITE_FWD(args)))
}
