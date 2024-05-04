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
	template<std::size_t argumentCount_, xieite::concepts::InvocableWithArgumentCount<argumentCount_> Functor_, typename... Arguments_>
	requires((argumentCount_ > 0) && !(sizeof...(Arguments_) % argumentCount_))
	constexpr void distributeArguments(Functor_&& functor, Arguments_&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocableWithArgumentCount<Functor_, argumentCount_>) {
		if constexpr (sizeof...(Arguments_) == argumentCount_) {
			static_cast<void>(std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...));
		} else {
			const std::tuple<Arguments_&&...> argumentsTuple = std::forward_as_tuple(XIEITE_FORWARD(arguments)...);
			([&functor, &argumentsTuple]<std::size_t... i_>(std::index_sequence<i_...>) {
				static_cast<void>(std::invoke(functor, std::get<i_>(std::move(argumentsTuple))...));
			})(std::make_index_sequence<argumentCount_>());
			([&functor, &argumentsTuple]<std::size_t... i_>(std::index_sequence<i_...>) {
				xieite::functors::distributeArguments<argumentCount_>(XIEITE_FORWARD(functor), std::get<i_ + argumentCount_>(std::move(argumentsTuple))...);
			})(std::make_index_sequence<sizeof...(Arguments_) - argumentCount_>());
		}
	}
}

#endif
