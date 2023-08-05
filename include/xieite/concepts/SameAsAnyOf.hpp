#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ANY_OF

#	include "../traits/IsSameAsAnyOf.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAnyOf = xieite::traits::IsSameAsAnyOf<Source, Targets...>::value;
}

#endif
