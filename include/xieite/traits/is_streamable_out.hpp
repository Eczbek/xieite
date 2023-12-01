#ifndef XIEITE_HEADER_TRAITS_IS_STREAMABLE_OUT
#	define XIEITE_HEADER_TRAITS_IS_STREAMABLE_OUT

#	include <type_traits>
#	include "../concepts/streamable_out.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsStreamableOut
	: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
}

#endif
