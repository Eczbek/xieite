#ifndef XIEITE_HEADER__TRAITS___STREAMABLE_OUT
#	define XIEITE_HEADER__TRAITS___STREAMABLE_OUT

#	include <type_traits>
#	include "../concepts/streamable_out.hpp"

namespace xieite::traits {
	template<typename Type>
	struct StreamableOut
	: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
}

#endif
