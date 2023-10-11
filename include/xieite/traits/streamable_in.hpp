#ifndef XIEITE_HEADER_TRAITS_STREAMABLE_IN
#	define XIEITE_HEADER_TRAITS_STREAMABLE_IN

#	include <type_traits>
#	include "../concepts/streamable_in.hpp"

namespace xieite::traits {
	template<typename Type>
	struct StreamableIn
	: std::bool_constant<xieite::concepts::StreamableIn<Type>> {};
}

#endif
