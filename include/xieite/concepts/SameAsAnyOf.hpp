#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ANY_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAnyOf = (std::same_as<Source, Targets> || ...);
}

#endif
