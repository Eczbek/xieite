module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:apply_as_tuple;

import std;
import :make_tuple;

export namespace xieite {
	template<typename F, typename V>
	constexpr auto apply_as_tuple(F&& fn, V&& x)
		XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::make_tuple(XIEITE_FWD(x))))

	template<typename T, typename V>
	[[nodiscard]] constexpr T apply_as_tuple(V&& x)
		XIEITE_ARROW_RET(xieite::apply_as_tuple(XIEITE_LIFT(T), XIEITE_FWD(x)))
}
