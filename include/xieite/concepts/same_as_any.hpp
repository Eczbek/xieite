#ifndef XIEITE_HEADER_CONCEPTS_SAME_AS_ANY
#	define XIEITE_HEADER_CONCEPTS_SAME_AS_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Source_, typename... Targets_>
	concept SameAsAny = (... || std::same_as<Source_, Targets_>);
}

#endif
