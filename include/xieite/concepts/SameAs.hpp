#ifndef XIEITE_HEADER_CONCEPTS_SAMEAS
#	define XIEITE_HEADER_CONCEPTS_SAMEAS

#	include <concepts>

namespace xieite::concepts {
	template<typename Any, typename... Others>
	concept SameAs = (std::same_as<Any, Others> || ...);
}

#endif
