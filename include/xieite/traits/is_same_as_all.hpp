#ifndef XIEITE_HEADER_TRAITS_IS_SAME_AS_ALL
#	define XIEITE_HEADER_TRAITS_IS_SAME_AS_ALL

#	include <type_traits>
#	include "../concepts/same_as_all.hpp"

namespace xieite::traits {
	template<typename Source_, typename... Targets_>
	struct IsSameAsAll
	: std::bool_constant<xieite::concepts::SameAsAll<Source_, Targets_...>> {};
}

#endif
