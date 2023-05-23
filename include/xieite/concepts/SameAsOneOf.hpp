#ifndef XIEITE_HEADER_CONCEPTS_SAMEASONEOF
#	define XIEITE_HEADER_CONCEPTS_SAMEASONEOF

#	include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept SameAsOneOf = (std::same_as<From, Tos> || ...);
}

#endif
