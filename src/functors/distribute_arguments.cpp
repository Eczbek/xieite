module;

#include <xieite/forward.hpp>

export module xieite:functors.distributeArguments;

import std;
import :types.Any;
import :types.List;

export namespace xieite::functors {
	template<std::size_t arity, typename Functor, typename... Arguments>
	requires((arity > 0) && !(sizeof...(Arguments) % arity) && xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::ApplyRange<std::is_invocable>::value)
	constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::types::List<xieite::types::Any>::Repeat<arity>::Prepend<Functor>::ApplyRange<std::is_nothrow_invocable>::value) {
		if constexpr (sizeof...(Arguments) == arity) {
			std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) {
				std::invoke(functor, std::get<i>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<arity>());
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) {
				xieite::functors::distributeArguments<arity>(XIEITE_FORWARD(functor), std::get<i + arity>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments) - arity>());
		}
	}
}
