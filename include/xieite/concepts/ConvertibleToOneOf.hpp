#ifndef XIEITE_HEADER_CONCEPTS_CONVERTIBLETOONEOF
#	define XIEITE_HEADER_CONCEPTS_CONVERTIBLETOONEOF

#	include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept ConvertibleToOneOf = (std::convertible_to<From, Tos> || ...);
}

#endif
