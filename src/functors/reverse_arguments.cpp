module;

#include <xieite/forward.hpp>

export module xieite:functors.reverseArguments;

import std;
import :containers.reverseTuple;
import :types.List;

export namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(xieite::types::List<Arguments...>::Reverse::template Prepend<Functor>::template ApplyRange<std::is_invocable>::value)
	constexpr typename xieite::types::List<Arguments...>::Reverse::template Prepend<Functor>::template ApplyRange<std::invoke_result>::type reverseArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::types::List<Arguments...>::Reverse::template Prepend<Functor>::template ApplyRange<std::is_nothrow_invocable>::value) {
		return std::apply(XIEITE_FORWARD(functor), xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}

	template<typename Structure, typename... Arguments>
	requires(xieite::types::List<Arguments...>::Reverse::template Prepend<Structure>::template ApplyRange<std::is_constructible>::value)
	[[nodiscard]] constexpr Structure reverseArguments(Arguments&&... arguments)
	noexcept(xieite::types::List<Arguments...>::Reverse::template Prepend<Structure>::template ApplyRange<std::is_nothrow_constructible>::value) {
		return std::make_from_tuple<Structure>(xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}
}
