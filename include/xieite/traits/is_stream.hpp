#ifndef XIEITE_HEADER_TRAITS_IS_STREAM
#	define XIEITE_HEADER_TRAITS_IS_STREAM

#	include <type_traits>
#	include "../concepts/stream.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsStream
	: std::bool_constant<xieite::concepts::Stream<Type_>> {};
}

#endif
