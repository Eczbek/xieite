#ifndef XIEITE_HEADER_TRAITS_IS_SAME_AS_ANY
#	define XIEITE_HEADER_TRAITS_IS_SAME_AS_ANY

#	include <type_traits>
#	include "../concepts/same_as_any.hpp"

namespace xieite::traits {
	template<typename Source_, typename... Targets_>
	struct IsSameAsAny
	: std::bool_constant<xieite::concepts::SameAsAny<Source_, Targets_...>> {};
}

#endif
