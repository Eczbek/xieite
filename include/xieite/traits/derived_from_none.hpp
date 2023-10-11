#ifndef XIEITE_HEADER_TRAITS_DERIVED_FROM_NONE
#	define XIEITE_HEADER_TRAITS_DERIVED_FROM_NONE

#	include <type_traits>
#	include "../concepts/derived_from_none.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromNone
	: std::bool_constant<xieite::concepts::DerivedFromNone<Derived, Bases...>> {};
}

#endif
