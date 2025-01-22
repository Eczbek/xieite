module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:pipe_op;

import std;

export namespace xieite::pipe_op {
	template<typename T, std::invocable<T> F>
	constexpr auto operator|(T&& arg, F&& fn)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(arg)))
}
