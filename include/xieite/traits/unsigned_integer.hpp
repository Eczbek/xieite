#ifndef XIEITE_HEADER_TRAITS_UNSIGNED_INTEGER
#	define XIEITE_HEADER_TRAITS_UNSIGNED_INTEGER

#	include <type_traits>
#	include "../concepts/unsigned_integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct UnsignedInteger
	: std::bool_constant<xieite::concepts::UnsignedInteger<Type>> {};
}

#endif
