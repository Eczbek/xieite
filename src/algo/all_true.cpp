module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:all_true;

import std;

export namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr bool all_true(F&& fn, Args&&... args)
	XIEITE_ARROW((... && std::invoke_r<bool>(fn, XIEITE_FWD(args))))
}
