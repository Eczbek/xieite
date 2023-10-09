#ifndef XIEITE_HEADER__TRAITS__IS_UNSIGNED_INTEGER
#	define XIEITE_HEADER__TRAITS__IS_UNSIGNED_INTEGER

#	include <type_traits>
#	include "../concepts/unsigned_integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsUnsignedInteger
	: std::bool_constant<xieite::concepts::UnsignedInteger<Type>> {};
}

#endif
