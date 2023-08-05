#ifndef XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ALL_OF

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToAllOf
	: std::bool_constant<(std::convertible_to<Source, Targets> && ...)> {};
}

#endif
