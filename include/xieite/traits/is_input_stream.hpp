#ifndef XIEITE_HEADER_TRAITS_IS_INPUT_STREAM
#	define XIEITE_HEADER_TRAITS_IS_INPUT_STREAM

#	include <type_traits>
#	include "../concepts/input_stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsInputStream
	: std::bool_constant<xieite::concepts::InputStream<Type>> {};
}

#endif
