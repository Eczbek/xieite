#ifndef XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY
#	define XIEITE_HEADER__CONCEPTS__DERIVED_FROM_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAny = (... || std::derived_from<Derived, Bases>);
}

#endif
