#ifndef XIEITE_HEADER_TRAITS_IS_FUNCTABLE
#	define XIEITE_HEADER_TRAITS_IS_FUNCTABLE

#	include <concepts>
#	include <functional>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct IsFunctable
	: std::false_type {};

	template<typename Functor_, typename Return_, typename... Arguments_>
	struct IsFunctable<Functor_, Return_(Arguments_...)>
	: std::bool_constant<requires(Functor_ functor, Arguments_... arguments) {
		{ std::invoke(functor, arguments...) } -> std::convertible_to<Return_>;
	}> {};
}

#endif
