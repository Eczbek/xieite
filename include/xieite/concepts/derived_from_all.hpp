#ifndef XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ALL
#	define XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived_, typename... Bases_>
	concept DerivedFromAll = (... && std::derived_from<Derived_, Bases_>);
}

#endif
