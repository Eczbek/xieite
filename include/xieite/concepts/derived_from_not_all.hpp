#ifndef XIEITE_HEADER_CONCEPTS_DERIVED_FROM_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_DERIVED_FROM_NOT_ALL

#	include "../concepts/derived_from_all.hpp"

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromNotAll = !xieite::concepts::DerivedFromAll<Derived, Bases...>;
}

#endif
