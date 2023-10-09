#ifndef XIEITE_HEADER__TRAITS__IS_INTEGER
#	define XIEITE_HEADER__TRAITS__IS_INTEGER

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsInteger
	: std::bool_constant<xieite::concepts::Integer<Type>> {};
}

#endif
