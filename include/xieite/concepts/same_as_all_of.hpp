#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ALL_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAllOf = (... || std::same_as<Source, Targets>);
}

#endif
