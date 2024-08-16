#ifndef XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ALL
#	define XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAll = (... && std::derived_from<Derived, Bases>);
}

#endif
