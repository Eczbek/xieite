module;

#include <xieite/forward.hpp>

export module xieite:functors.recursivelyDistributeArguments;

import std;
import :containers.spliceTuple;
import :types.Any;
import :types.List;

export namespace xieite::functors {
	template<std::size_t arity, std::size_t previousResultIndex = 0, typename Functor, typename... Arguments>
	requires((arity > previousResultIndex) && (arity <= sizeof...(Arguments)) && ((arity == 1) || ((arity > 1) && !((sizeof...(Arguments) - 1) % (arity - 1)))) && xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::ApplyRange<std::is_invocable>::value)
	/* discardable */ constexpr decltype(auto) recursivelyDistributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::ApplyRange<std::is_nothrow_invocable>::value) {
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
