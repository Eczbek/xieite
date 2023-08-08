#ifndef XIEITE_HEADER__TRAITS__IS_BASE_OF_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_BASE_OF_ALL_OF

#	include <type_traits>
#	include "../concepts/BaseOfAllOf.hpp"

namespace xieite::traits {
	template<typename Base, typename... Derived>
	struct IsBaseOfAllOf
	: std::bool_constant<xieite::concepts::BaseOfAllOf<Base, Derived...>> {};
}

#endif
