module;

#include <xieite/forward.hpp>

export module xieite:functors.recursivelyDistributeArguments;

import std;
import :containers.spliceTuple;
import :types.Any;

template<std::size_t>
using RecursivelyDistributeArgumentsAny = xieite::types::Any;

template<template<typename...> typename Template, typename Functor, std::size_t arity>
using RecursivelyDistributeArgumentsArity = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
	return Template<Functor, RecursivelyDistributeArgumentsAny<i>...>();
})(std::make_index_sequence<arity>()));

export namespace xieite::functors {
	template<std::size_t arity, std::size_t previousResultIndex = 0, typename Functor, typename... Arguments>
	requires(RecursivelyDistributeArgumentsArity<std::is_invocable, Functor, arity>::value && (arity > previousResultIndex) && (arity <= sizeof...(Arguments)) && ((arity == 1) || ((arity > 1) && !((sizeof...(Arguments) - 1) % (arity - 1)))))
	/* discardable */ constexpr decltype(auto) recursivelyDistributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(RecursivelyDistributeArgumentsArity<std::is_nothrow_invocable, Functor, arity>::value) {
		if constexpr (sizeof...(Arguments) == arity) {
			return std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			return ([&functor, resultsTuple = xieite::containers::spliceTuple<previousResultIndex + arity>(argumentsTuple, std::forward_as_tuple(std::apply(functor, xieite::containers::spliceTuple<arity, sizeof...(Arguments) - arity>(argumentsTuple))))]<std::size_t... i>(std::index_sequence<i...>) -> decltype(auto) {
				return xieite::functors::recursivelyDistributeArguments<arity, previousResultIndex>(XIEITE_FORWARD(functor), std::get<i + arity>(std::move(resultsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments) - arity + 1>());
		}
	}
}

// TODO: Replace helpers with `xieite::types::List`
