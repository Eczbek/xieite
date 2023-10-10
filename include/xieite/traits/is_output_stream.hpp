#ifndef XIEITE_HEADER__TRAITS__IS_OUTPUT_STREAM
#	define XIEITE_HEADER__TRAITS__IS_OUTPUT_STREAM

#	include <type_traits>
#	include "../concepts/output_stream.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsOutputStream
	: std::bool_constant<xieite::concepts::OutputStream<Type>> {};
}

#endif
