#ifndef XIEITE_HEADER_TRAITS_INTEGER
#	define XIEITE_HEADER_TRAITS_INTEGER

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Integer
	: std::bool_constant<xieite::concepts::Integer<Type>> {};
}

#endif
