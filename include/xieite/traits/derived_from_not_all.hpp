#ifndef XIEITE_HEADER_TRAITS_DERIVED_FROM_NOT_ALL
#	define XIEITE_HEADER_TRAITS_DERIVED_FROM_NOT_ALL

#	include <type_traits>
#	include "../concepts/derived_from_not_all.hpp"

namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct DerivedFromNotAll
	: std::bool_constant<xieite::concepts::DerivedFromNotAll<Derived, Bases...>> {};
}

#endif
