#ifndef XIEITE_HEADER_TRAITS_IS_INTEGER
#	define XIEITE_HEADER_TRAITS_IS_INTEGER

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsInteger
	: std::bool_constant<xieite::concepts::Integer<Type>> {};
}

#endif
