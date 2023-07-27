#ifndef XIEITE_HEADER_CONCEPTS_SAMEASORDERIVEDFROM
#	define XIEITE_HEADER_CONCEPTS_SAMEASORDERIVEDFROM

#	include <concepts>
#	include "../concepts/SameAs.hpp"

namespace xieite::concepts {
	template<typename Any, typename... Bases>
	concept SameAsOrDerivedFrom = xieite::concepts::SameAs<Any, Bases...> || (std::derived_from<Any, Bases> || ...);
}

#endif
