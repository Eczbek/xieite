#ifndef XIEITE_HEADER__TRAITS__IS_SAME_AS_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_SAME_AS_ANY_OF

#	include <type_traits>
#	include "../concepts/SameAsAnyOf.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsSameAsAnyOf
	: std::bool_constant<xieite::concepts::SameAsAnyOf<Source, Targets...>> {};
}

#endif
