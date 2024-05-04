#ifndef XIEITE_HEADER_FUNCTORS_REVERSE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTOR_REVERSE_ARGUMENTS

#	include <tuple>
#	include <type_traits>
#	include "../containers/reverse_tuple.hpp"
#	include "../macros/forward.hpp"
#	include "../types/list.hpp"

namespace xieite::functors {
	template<typename... Arguments_, typename Functor_>
	requires(xieite::types::List<Arguments_...>::Reverse::template Prepend<Functor_>::template Apply<std::is_invocable>::value)
	constexpr typename xieite::types::List<Arguments_...>::Reverse::Prepend<Functor_>::Apply<std::invoke_result>::type reverseArguments(Functor_&& functor, Arguments_&&... arguments)
	noexcept(xieite::types::List<Arguments_...>::Reverse::template Prepend<Functor_>::template Apply<std::is_nothrow_invocable>::value) {
		return std::apply(XIEITE_FORWARD(functor), xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}

	template<typename Structure_, typename... Arguments_>
	requires(xieite::types::List<Arguments_...>::Reverse::template Prepend<Structure_>::template Apply<std::is_constructible>::value)
	[[nodiscard]] constexpr Structure_ reverseArguments(Arguments_&&... arguments)
	noexcept(xieite::types::List<Arguments_...>::Reverse::template Prepend<Structure_>::template Apply<std::is_nothrow_constructible>::value) {
		return std::make_from_tuple<Structure_>(xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...)));
	}
}

#endif
