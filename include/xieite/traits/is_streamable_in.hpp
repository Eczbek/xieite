#ifndef XIEITE_HEADER_TRAITS_IS_STREAMABLE_IN
#	define XIEITE_HEADER_TRAITS_IS_STREAMABLE_IN

#	include <type_traits>
#	include "../concepts/streamable_in.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsStreamableIn
	: std::bool_constant<xieite::concepts::StreamableIn<Type>> {};
}

#endif
