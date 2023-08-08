#ifndef XIEITE_HEADER__CONCEPTS__BASE_OF_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__BASE_OF_ALL_OF

#	include "../concepts/BaseOf.hpp"

namespace xieite::concepts {
	template<typename Base, typename... Derived>
	concept BaseOfAllOf = (xieite::concepts::BaseOf<Base, Derived> && ...);
}

#endif
