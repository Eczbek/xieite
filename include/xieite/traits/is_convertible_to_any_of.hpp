#ifndef XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_CONVERTIBLE_TO_ANY_OF

#	include <type_traits>
#	include "../concepts/convertible_to_any_of.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToAnyOf
	: std::bool_constant<xieite::concepts::ConvertibleToAnyOf<Source, Targets...>> {};
}

#endif
