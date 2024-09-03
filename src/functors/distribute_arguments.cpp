module;

#include "../macros/forward.hpp"

export module xieite:functors.distributeArguments;

import std;
import :types.Any;

template<std::size_t>
using DistributeArgumentsAny = xieite::types::Any;

template<template<typename...> typename Template, typename Functor, std::size_t arity>
using DistributeArgumentsArity = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
	return Template<Functor, DistributeArgumentsAny<i>...>();
})(std::make_index_sequence<arity>()));

export namespace xieite::functors {
	template<std::size_t arity, typename Functor, typename... Arguments>
	requires(DistributeArgumentsArity<std::is_invocable, Functor, arity>::value && (arity > 0) && !(sizeof...(Arguments) % arity))
	constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(DistributeArgumentsArity<std::is_nothrow_invocable, Functor, arity>::value) {
		if constexpr (sizeof...(Arguments) == arity) {
			std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) -> void {
				std::invoke(functor, std::get<i>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<arity>());
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) -> void {
				xieite::functors::distributeArguments<arity>(XIEITE_FORWARD(functor), std::get<i + arity>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments) - arity>());
		}
	}
}

// TODO: Replace helpers with `xieite::types::List`
