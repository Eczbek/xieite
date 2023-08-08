#ifndef XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ANY_OF

#	include <type_traits>
#	include "../concepts/DerivedFromAnyOf.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAnyOf
	: std::bool_constant<xieite::concepts::DerivedFromAnyOf<Derived, Bases...>> {};
}

#endif
