module;

#include <xieite/fwd.hpp>

export module xieite:all_true;

import std;
import :is_nothrow_invoc;

export namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr bool all_true(F&& fn, Args&&... args)
	noexcept((... && xieite::is_nothrow_invoc<F, bool(Args...)>)) {
		return (... && std::invoke_r<bool>(fn, XIEITE_FWD(args)));
	}
}
