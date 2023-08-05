#ifndef XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_ALL_OF

#	include <type_traits>
#	include "../concepts/NoThrowConvertibleTo.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToAllOf
	: std::bool_constant<(xieite::concepts::NoThrowConvertibleTo<Source, Targets> && ...)> {};
}

#endif
