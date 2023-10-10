#ifndef XIEITE_HEADER__TRAITS__IS_SAME_AS_NOT_ALL
#	define XIEITE_HEADER__TRAITS__IS_SAME_AS_NOT_ALL

#	include <type_traits>
#	include "../concepts/same_as_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsSameAsNotAll
	: std::bool_constant<xieite::concepts::SameAsNotAll<Source, Targets...>> {};
}

#endif
