#ifndef XIEITE_HEADER__TRAITS__IS_STREAMABLE_IN
#	define XIEITE_HEADER__TRAITS__IS_STREAMABLE_IN

#	include <type_traits>
#	include "../concepts/streamable_in.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsStreamableIn
	: std::bool_constant<xieite::concepts::StreamableIn<Type>> {};
}

#endif
