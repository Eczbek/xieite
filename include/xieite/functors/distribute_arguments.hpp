#ifndef XIEITE_HEADER_FUNCTORS_DISTRIBUTE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTORS_DISTRIBUTE_ARGUMENTS

#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <utility>
#	include "../concepts/invocable_with_arity.hpp"
#	include "../concepts/no_throw_invocable_with_arity.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<std::size_t arity, xieite::concepts::InvocableWithArity<arity> Functor, typename... Arguments>
	requires((arity > 0) && !(sizeof...(Arguments) % arity))
	constexpr void distributeArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor, arity>) {
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

#endif
