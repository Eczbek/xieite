#ifndef XIEITE_HEADER__TRAITS__IS_SAME_AS_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_SAME_AS_ANY_OF

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsSameAsAnyOf
	: std::bool_constant<(std::same_as<Source, Targets> || ...)> {};
}

#endif
