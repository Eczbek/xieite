#ifndef XIEITE_HEADER__CONCEPTS__SAME_AS_ALL
#	define XIEITE_HEADER__CONCEPTS__SAME_AS_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAll = (... || std::same_as<Source, Targets>);
}

#endif
