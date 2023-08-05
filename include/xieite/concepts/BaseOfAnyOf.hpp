#ifndef XIEITE_HEADER__CONCEPTS__BASE_OF_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__BASE_OF_ANY_OF

#	include "../traits/IsBaseOfAnyOf.hpp"

namespace xieite::concepts {
	template<typename Base, typename... Derived>
	concept BaseOfAnyOf = xieite::traits::IsBaseOfAnyOf<Base, Derived...>::value;
}

#endif
