#ifndef XIEITE_HEADER_TRAITS_IS_DERIVED_FROM_ALL
#	define XIEITE_HEADER_TRAITS_IS_DERIVED_FROM_ALL

#	include <type_traits>
#	include "../concepts/derived_from_all.hpp"

namespace xieite::traits {
	template<typename Derived_, typename... Bases_>
	struct IsDerivedFromAll
	: std::bool_constant<xieite::concepts::DerivedFromAll<Derived_, Bases_...>> {};
}

#endif
