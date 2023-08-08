#ifndef XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL_OF

#	include <type_traits>
#	include "../concepts/DerivedFromAllOf.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAllOf
	: std::bool_constant<xieite::concepts::DerivedFromAllOf<Derived, Bases...>> {};
}

#endif
