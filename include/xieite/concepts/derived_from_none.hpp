#ifndef XIEITE_HEADER_CONCEPTS_DERIVED_FROM_NONE
#	define XIEITE_HEADER_CONCEPTS_DERIVED_FROM_NONE

#	include "../concepts/derived_from_any.hpp"

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromNone = !xieite::concepts::DerivedFromAny<Derived, Bases...>;
}

#endif
