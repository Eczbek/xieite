module;

#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:tuple_fwd;

import std;
import :is_spec;

export namespace xieite {
	template<xieite::is_spec<std::tuple> Tuple>
	[[nodiscard]] constexpr auto tuple_fwd(Tuple&& tuple) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(tuple));
	}
}
