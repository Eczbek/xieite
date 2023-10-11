#ifndef XIEITE_HEADER_CONCEPTS_SAME_AS_ALL
#	define XIEITE_HEADER_CONCEPTS_SAME_AS_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsAll = (... || std::same_as<Source, Targets>);
}

#endif
