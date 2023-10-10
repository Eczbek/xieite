#ifndef XIEITE_HEADER__TRAITS___SAME_AS_NONE
#	define XIEITE_HEADER__TRAITS___SAME_AS_NONE

#	include <type_traits>
#	include "../concepts/same_as_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct SameAsNone
	: std::bool_constant<xieite::concepts::SameAsNone<Source, Targets...>> {};
}

#endif
