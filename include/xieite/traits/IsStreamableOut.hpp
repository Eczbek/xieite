#ifndef XIEITE_HEADER__TRAITS__IS_STREAMABLE_OUT
#	define XIEITE_HEADER__TRAITS__IS_STREAMABLE_OUT

#	include <type_traits>
#	include "../concepts/StreamableOut.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsStreamableOut
	: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
}

#endif
