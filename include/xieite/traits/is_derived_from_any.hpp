#ifndef XIEITE_HEADER_TRAITS_IS_DERIVED_FROM_ANY
#	define XIEITE_HEADER_TRAITS_IS_DERIVED_FROM_ANY

#	include <type_traits>
#	include "../concepts/derived_from_any.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAny
	: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
}

#endif
