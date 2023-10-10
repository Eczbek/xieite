#ifndef XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL
#	define XIEITE_HEADER__CONCEPTS__IS_DERIVED_FROM_ALL

#	include <type_traits>
#	include "../concepts/derived_from_all.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromAll
	: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
}

#endif
