#ifndef XIEITE_HEADER__TRAITS__IS_SAME_AS_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_SAME_AS_ALL_OF

#	include <type_traits>
#	include "../concepts/same_as_all_of.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsSameAsAllOf
	: std::bool_constant<xieite::concepts::SameAsAllOf<Source, Targets...>> {};
}

#endif
