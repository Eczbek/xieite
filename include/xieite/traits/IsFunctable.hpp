#ifndef XIEITE_HEADER__TRAITS__IS_FUNCTABLE
#	define XIEITE_HEADER__TRAITS__IS_FUNCTABLE

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	struct IsFunctable
	: std::false_type {};

	template<typename Functor, typename Result, typename... Parameters>
	struct IsFunctable<Functor, Result(Parameters...)>
	: std::bool_constant<std::invocable<Functor, Parameters...> && std::convertible_to<Result, std::invoke_result_t<Functor, Parameters...>>> {};
}

#endif
