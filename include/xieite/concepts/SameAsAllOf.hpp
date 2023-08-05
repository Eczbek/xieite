#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ALL_OF

#	include "../traits/IsSameAsAllOf.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAllOf = xieite::traits::IsSameAsAllOf<Source, Targets...>::value;
}

#endif
