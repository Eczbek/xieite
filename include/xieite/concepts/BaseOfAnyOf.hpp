#ifndef XIEITE_HEADER__CONCEPTS__BASE_OF_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__BASE_OF_ANY_OF

#	include "../concepts/BaseOf.hpp"

namespace xieite::concepts {
	template<typename Base, typename... Derived>
	concept BaseOfAnyOf = (xieite::concepts::BaseOf<Base, Derived> || ...);
}

#endif