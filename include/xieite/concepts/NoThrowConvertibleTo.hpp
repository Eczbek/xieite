#ifndef XIEITE_HEADER_CONCEPTS_NOTHROWCONVERTIBLETO
#	define XIEITE_HEADER_CONCEPTS_NOTHROWCONVERTIBLETO

#	include <type_traits>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept NoThrowConvertibleTo = (std::is_nothrow_convertible_v<From, Tos> || ...);
}

#endif
