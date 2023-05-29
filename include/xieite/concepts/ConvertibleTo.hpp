#ifndef XIEITE_HEADER_CONCEPTS_CONVERTIBLETO
#	define XIEITE_HEADER_CONCEPTS_CONVERTIBLETO

#	include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept ConvertibleTo = (std::convertible_to<From, Tos> || ...);
}

#endif
