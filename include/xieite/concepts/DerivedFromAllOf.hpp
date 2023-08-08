#ifndef XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ALL_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAllOf = (std::derived_from<Derived, Bases> && ...);
}

#endif
