#ifndef XIEITE_HEADER_CONCEPTS_DERIVEDFROM
#	define XIEITE_HEADER_CONCEPTS_DERIVEDFROM

#	include <concepts>

namespace xieite::concepts {
	template<typename Any, typename... Others>
	concept DerivedFrom = (std::derived_from<Any, Others> || ...);
}

#endif
