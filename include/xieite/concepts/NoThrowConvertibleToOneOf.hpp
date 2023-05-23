#ifndef XIEITE_HEADER_CONCEPTS_NOTHROWCONVERTIBLETOONEOF
#	define XIEITE_HEADER_CONCEPTS_NOTHROWCONVERTIBLETOONEOF

#	include <xieite/concepts/NoThrowConvertibleTo.hpp>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept NoThrowConvertibleToOneOf = (xieite::concepts::NoThrowConvertibleTo<From, Tos> || ...);
}

#endif
