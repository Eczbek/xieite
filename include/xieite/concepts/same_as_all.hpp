#ifndef XIEITE_HEADER_CONCEPTS_SAME_AS_ALL
#	define XIEITE_HEADER_CONCEPTS_SAME_AS_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Source_, typename... Targets_>
	concept SameAsAll = (... || std::same_as<Source_, Targets_>);
}

#endif
