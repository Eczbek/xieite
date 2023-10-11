#ifndef XIEITE_HEADER_TRAITS_SAME_AS_NONE
#	define XIEITE_HEADER_TRAITS_SAME_AS_NONE

#	include <type_traits>
#	include "../concepts/same_as_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct SameAsNone
	: std::bool_constant<xieite::concepts::SameAsNone<Source, Targets...>> {};
}

#endif
