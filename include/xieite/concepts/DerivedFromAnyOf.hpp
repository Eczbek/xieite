#ifndef XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY_OF

#	include "../traits/IsDerivedFromAnyOf.hpp"

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAnyOf = xieite::traits::IsDerivedFromAnyOf<Derived, Bases...>::value;
}

#endif
