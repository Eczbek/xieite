#ifndef XIEITE_HEADER_TRAITS_IS_STREAM
#	define XIEITE_HEADER_TRAITS_IS_STREAM

#	include <type_traits>
#	include "../concepts/stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsStream
	: std::bool_constant<xieite::concepts::Stream<Type>> {};
}

#endif
