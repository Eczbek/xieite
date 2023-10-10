#pragma once

#include <concepts>
#include <functional>
#include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct Functable
	: std::false_type {};

	template<typename Functor, typename SignatureResult, typename... SignatureArguments>
	struct Functable<Functor, SignatureResult(SignatureArguments...)>
	: std::bool_constant<requires(Functor functor, SignatureArguments... arguments) {
		{ std::invoke(functor, arguments...) } -> std::convertible_to<SignatureResult>;
	}> {};
}
