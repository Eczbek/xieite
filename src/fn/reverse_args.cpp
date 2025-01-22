module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:reverse_args;

import std;
import :reverse_tuple;

export namespace xieite {
	template<typename F, typename... Args>
	constexpr auto reverse_args(F&& fn, Args&&... args)
		XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::reverse_tuple(std::forward_as_tuple(XIEITE_FWD(args)...))))

	template<typename T, typename... Args>
	[[nodiscard]] constexpr T reverse_args(Args&&... args)
		XIEITE_ARROW_RET(xieite::reverse_args(XIEITE_LIFT(T), XIEITE_FWD(args)...))
}
