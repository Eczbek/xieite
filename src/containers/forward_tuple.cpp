module;

#include <xieite/forward.hpp>

export module xieite:containers.forwardTuple;

import std;
import :concepts.SpecializationOf;

export namespace xieite::containers {
	template<xieite::concepts::SpecializationOf<std::tuple> Tuple>
	[[nodiscard]] constexpr auto forwardTuple(Tuple&& tuple) noexcept {
		return std::apply(
			[](auto&&... values) {
				return std::forward_as_tuple(XIEITE_FORWARD(values)...);
			},
			XIEITE_FORWARD(tuple)
		);
	}
}
