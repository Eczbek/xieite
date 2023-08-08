#ifndef XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ALL_OF

#	include <type_traits>
#	include "../concepts/ConvertibleToAllOf.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToAllOf
	: std::bool_constant<xieite::concepts::ConvertibleToAllOf<Source, Targets...>> {};
}

#endif
