#ifndef XIEITE_HEADER__TRAITS___INPUT_STREAM
#	define XIEITE_HEADER__TRAITS___INPUT_STREAM

#	include <type_traits>
#	include "../concepts/input_stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct InputStream
	: std::bool_constant<xieite::concepts::InputStream<Type>> {};
}

#endif
