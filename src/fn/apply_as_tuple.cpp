module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:apply_as_tuple;

import std;
import :make_tuple;

export namespace xieite {
	template<typename F, typename V>
	constexpr auto apply_as_tuple(F&& fn, V&& value)
	XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::make_tuple(XIEITE_FWD(value))))

	template<typename T, typename V>
	[[nodiscard]] constexpr T apply_as_tuple(V&& value)
	XIEITE_ARROW(std::make_from_tuple<T>(xieite::make_tuple(XIEITE_FWD(value))))
}
