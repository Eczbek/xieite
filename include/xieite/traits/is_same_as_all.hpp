#ifndef XIEITE_HEADER__TRAITS__IS_SAME_AS_ALL
#	define XIEITE_HEADER__TRAITS__IS_SAME_AS_ALL

#	include <type_traits>
#	include "../concepts/same_as_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsSameAsAll
	: std::bool_constant<xieite::concepts::SameAsAll<Source, Targets...>> {};
}

#endif
