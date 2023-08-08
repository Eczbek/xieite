#ifndef XIEITE_HEADER__TRAITS__IS_BASE_OF_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_BASE_OF_ANY_OF

#	include <type_traits>
#	include "../concepts/BaseOfAnyOf.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsBaseOfAnyOf
	: std::bool_constant<xieite::concepts::BaseOfAnyOf<Source, Targets...>> {};
}

#endif
