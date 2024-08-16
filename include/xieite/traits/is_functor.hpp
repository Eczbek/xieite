#ifndef XIEITE_HEADER_TRAITS_IS_FUNCTOR
#	define XIEITE_HEADER_TRAITS_IS_FUNCTOR

#	include <concepts>
#	include <functional>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct IsFunctor
	: std::false_type {};

	template<typename Type, typename Return, typename... Arguments>
	struct IsFunctor<Type, Return(Arguments...)>
	: std::bool_constant<requires(Type functor, Arguments... arguments) {
		{ std::invoke(functor, arguments...) } -> std::convertible_to<Return>;
	}> {};
}

#endif
