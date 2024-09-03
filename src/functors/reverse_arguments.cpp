module;

#include "../macros/forward.hpp"

export module xieite:functors.reverseArguments;

import std;
import :containers.reverseTuple;


template<template<typename...> typename Template, typename... Arguments>
using ReverseApply = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
	return Template<std::tuple_element_t<sizeof...(Arguments) - i - 1, std::tuple<Arguments...>>...>();
})(std::index_sequence_for<Arguments...>()));

export namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(ReverseApply<std::is_invocable, Functor, Arguments...>::value)
	constexpr typename ReverseApply<std::invoke_result, Arguments..., Functor>::type reverseArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(ReverseApply<std::is_nothrow_invocable, Arguments..., Functor>::value) {
		return std::apply(XIEITE_FORWARD(functor), xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}

	template<typename Structure, typename... Arguments>
	requires(ReverseApply<std::is_constructible, Arguments..., Structure>::value)
	[[nodiscard]] constexpr Structure reverseArguments(Arguments&&... arguments)
	noexcept(ReverseApply<std::is_nothrow_constructible, Arguments..., Structure>::value) {
		return std::make_from_tuple<Structure>(xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}
}

// TODO: Replace helper with `xieite::types::List`
