#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ANY
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAny = (... || std::same_as<Source, Targets>);
}

#endif
