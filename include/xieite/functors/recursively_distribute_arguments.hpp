#ifndef XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS

#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <utility>
#	include "../concepts/invocable_with_arity.hpp"
#	include "../concepts/no_throw_invocable_with_arity.hpp"
#	include "../containers/splice_tuple.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<std::size_t arity, std::size_t previousResultIndex = 0, xieite::concepts::InvocableWithArity<arity> Functor, typename... Arguments>
	requires((arity > previousResultIndex) && (arity <= sizeof...(Arguments)) && ((arity == 1) || (arity > 1) && !((sizeof...(Arguments) - 1) % (arity - 1))))
	constexpr decltype(auto) recursivelyDistributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor, arity>) {
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

#endif
