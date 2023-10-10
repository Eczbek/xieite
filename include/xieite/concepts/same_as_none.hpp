#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_NONE
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_NONE

#	include "../concepts/same_as_any.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsNone = !xieite::concepts::SameAsAny<Source, Targets...>;
}

#endif
