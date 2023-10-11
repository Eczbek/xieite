#ifndef XIEITE_HEADER_TRAITS_STREAM
#	define XIEITE_HEADER_TRAITS_STREAM

#	include <type_traits>
#	include "../concepts/stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Stream
	: std::bool_constant<xieite::concepts::Stream<Type>> {};
}

#endif
