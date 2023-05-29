#ifndef XIEITE_HEADER_CONCEPTS_SAMEAS
#	define XIEITE_HEADER_CONCEPTS_SAMEAS

#	include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept SameAs = (std::same_as<From, Tos> || ...);
}

#endif
