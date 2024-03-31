#ifndef XIEITE_HEADER_FUNCTORS_DISTRIBUTE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTORS_DISTRIBUTE_ARGUMENTS

#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <utility>
#	include "../concepts/invocable_with_argument_count.hpp"
#	include "../concepts/no_throw_invocable_with_argument_count.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<std::size_t argumentCount, xieite::concepts::InvocableWithArgumentCount<argumentCount> Functor, typename... Arguments>
	requires((argumentCount > 0) && !(sizeof...(Arguments) % argumentCount))
	constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor, argumentCount>) {
		if constexpr (sizeof...(Arguments) == argumentCount) {
			static_cast<void>(std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...));
		} else {
			const std::tuple<Arguments&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) {
				static_cast<void>(std::invoke(functor, std::get<i>(std::move(argumentsTuple))...));
			})(std::make_index_sequence<argumentCount>());
			([&functor, &argumentsTuple]<std::size_t... i>(std::index_sequence<i...>) {
				xieite::functors::distributeArguments<argumentCount>(XIEITE_FORWARD(functor), std::get<i + argumentCount>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments) - argumentCount>());
		}
	}
}

#endif
