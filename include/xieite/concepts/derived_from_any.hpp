#ifndef XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ANY
#	define XIEITE_HEADER_CONCEPTS_DERIVED_FROM_ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Derived_, typename... Bases_>
	concept DerivedFromAny = (... || std::derived_from<Derived_, Bases_>);
}

#endif
