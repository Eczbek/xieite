#ifndef XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTORS_RECURSIVELY_DISTRIBUTE_ARGUMENTS

#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <utility>
#	include "../concepts/invocable_with_argument_count.hpp"
#	include "../concepts/no_throw_invocable_with_argument_count.hpp"
#	include "../containers/splice_tuple.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<std::size_t argumentCount, std::size_t previousResultIndex = 0, xieite::concepts::InvocableWithArgumentCount<argumentCount> Functor, typename... Arguments>
	requires((argumentCount > previousResultIndex) && (argumentCount <= sizeof...(Arguments)) && ((argumentCount == 1) || (argumentCount > 1) && !((sizeof...(Arguments) - 1) % (argumentCount - 1))))
	constexpr decltype(auto) recursivelyDistributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor, argumentCount>) {
		if constexpr (sizeof...(Arguments) == argumentCount) {
			return std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			return ([&functor, resultsTuple = xieite::containers::spliceTuple<previousResultIndex + argumentCount>(argumentsTuple, std::forward_as_tuple(std::apply(functor, xieite::containers::spliceTuple<argumentCount, sizeof...(Arguments) - argumentCount>(argumentsTuple))))]<std::size_t... i>(std::index_sequence<i...>) -> decltype(auto) {
				return xieite::functors::recursivelyDistributeArguments<argumentCount, previousResultIndex>(XIEITE_FORWARD(functor), std::get<i + argumentCount>(std::move(resultsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments) - argumentCount + 1>());
		}
	}
}

#endif
