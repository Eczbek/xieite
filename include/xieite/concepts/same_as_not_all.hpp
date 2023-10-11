#ifndef XIEITE_HEADER_CONCEPTS_SAME_AS_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_SAME_AS_NOT_ALL

#	include "../concepts/same_as_all.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept SameAsNotAll = !xieite::concepts::SameAsAll<Source, Targets...>;
}

#endif