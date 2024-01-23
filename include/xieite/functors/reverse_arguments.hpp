#ifndef XIEITE_HEADER_FUNCTORS_REVERSE_ARGUMENTS
#	define XIEITE_HEADER_FUNCTOR_REVERSE_ARGUMENTS

#	include <tuple>
#	include <type_traits>
#	include <utility>
#	include "../functors/reverse_tuple.hpp"
#	include "../types/list.hpp"

namespace xieite::functors {
	template<typename... Arguments, typename Functor>
	requires(xieite::types::List<Arguments...>::Reverse::template Prepend<Functor>::template Apply<std::is_invocable>::value)
	constexpr typename xieite::types::List<Arguments...>::Reverse::Prepend<Functor>::Apply<std::invoke_result>::type reverseArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::types::List<Arguments...>::Reverse::template Prepend<Functor>::template Apply<std::is_nothrow_invocable>::value) {
		return std::apply(std::forward<Functor>(functor), xieite::functors::reverseTuple(std::forward_as_tuple(std::forward<Arguments>(arguments)...)));
	}

	template<typename Structure, typename... Arguments>
	requires(xieite::types::List<Arguments...>::Reverse::template Prepend<Structure>::template Apply<std::is_constructible>::value)
	constexpr Structure reverseArguments(Arguments&&... arguments)
	noexcept(xieite::types::List<Arguments...>::Reverse::template Prepend<Structure>::template Apply<std::is_nothrow_constructible>::value) {
		return std::make_from_tuple<Structure>(xieite::functors::reverseTuple(std::forward_as_tuple(std::forward<Arguments>(arguments)...)));
	}
}

#endif
