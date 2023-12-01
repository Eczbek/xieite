#ifndef XIEITE_HEADER_TRAITS_IS_FUNCTABLE
#	define XIEITE_HEADER_TRAITS_IS_FUNCTABLE

#	include <concepts>
#	include <functional>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct IsFunctable
	: std::false_type {};

	template<typename Functor, typename SignatureResult, typename... SignatureArguments>
	struct IsFunctable<Functor, SignatureResult(SignatureArguments...)>
	: std::bool_constant<requires(Functor functor, SignatureArguments... arguments) {
		{ std::invoke(functor, arguments...) } -> std::convertible_to<SignatureResult>;
	}> {};
}

#endif
