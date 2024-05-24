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
	template<std::size_t arity_, xieite::concepts::InvocableWithArity<arity_> Functor_, typename... Arguments_>
	requires((arity_ > 0) && !(sizeof...(Arguments_) % arity_))
	constexpr void distributeArguments(Functor_&& functor, Arguments_&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArity<Functor_, arity_>) {
		if constexpr (sizeof...(Arguments_) == arity_) {
			std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		} else {
			const std::tuple<Arguments_&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			([&functor, &argumentsTuple]<std::size_t... i_>(std::index_sequence<i_...>) {
				std::invoke(functor, std::get<i_>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<arity_>());
			([&functor, &argumentsTuple]<std::size_t... i_>(std::index_sequence<i_...>) {
				xieite::functors::distributeArguments<arity_>(XIEITE_FORWARD(functor), std::get<i_ + arity_>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments_) - arity_>());
		}
	}
}

#endif
