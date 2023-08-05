#ifndef XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ALL_OF

#	include "../traits/IsDerivedFromAllOf.hpp"

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAllOf = xieite::traits::IsDerivedFromAllOf<Derived, Bases...>::value;
}

#endif
