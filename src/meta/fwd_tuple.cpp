module;

#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:fwd_tuple;

import std;
import :is_spec;

export namespace xieite {
	template<xieite::is_spec<std::tuple> Tuple>
	[[nodiscard]] constexpr auto fwd_tuple(Tuple&& tuple) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(tuple));
	}
}
