#ifndef XIEITE_HEADER_TRAITS_IS_FUNCTABLE
#	define XIEITE_HEADER_TRAITS_IS_FUNCTABLE

#	include <concepts>
#	include <functional>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct IsFunctable
	: std::false_type {};

	template<typename Functor, typename Result, typename... Arguments>
	struct IsFunctable<Functor, Result(Arguments...)>
	: std::bool_constant<requires(Functor functor, Arguments... arguments) {
		{ std::invoke(functor, arguments...) } -> std::convertible_to<Result>;
	}> {};
}

#endif
