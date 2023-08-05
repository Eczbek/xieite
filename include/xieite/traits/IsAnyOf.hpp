#ifndef XIEITE_HEADER__TRAITS__IS_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_ANY_OF

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename, template<typename> typename...>
    struct IsAnyOf
    : std::false_type {};

	template<typename Type, template<typename> typename... Traits>
	requires((requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	} && ...))
	struct IsAnyOf<Type, Traits...>
    : std::bool_constant<(Traits<Type>::value || ...)> {};
}

#endif
