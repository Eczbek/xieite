module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.reverseArguments;

import std;
import :containers.reverseTuple;
import :types.List;

export namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	constexpr auto reverseArguments(Functor&& functor, Arguments&&... arguments)
	XIEITE_ARROW(std::apply(XIEITE_FORWARD(functor), xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...))))

	template<typename Structure, typename... Arguments>
	[[nodiscard]] constexpr Structure reverseArguments(Arguments&&... arguments)
	XIEITE_ARROW_BASE(std::make_from_tuple<Structure>(xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...))))
}
