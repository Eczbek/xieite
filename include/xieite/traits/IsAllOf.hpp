#ifndef XIEITE_HEADER__TRAITS__IS_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_ALL_OF

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename, template<typename> typename...>
    struct IsAllOf
    : std::false_type {};

	template<typename Type, template<typename> typename... Traits>
	requires((requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	} && ...))
	struct IsAllOf<Type, Traits...>
    : std::bool_constant<(Traits<Type>::value && ...)> {};
}

#endif
