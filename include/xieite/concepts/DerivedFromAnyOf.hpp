#ifndef XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAnyOf = (std::derived_from<Derived, Bases> || ...);
}

#endif
