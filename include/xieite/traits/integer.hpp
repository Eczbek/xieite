#ifndef XIEITE_HEADER__TRAITS___INTEGER
#	define XIEITE_HEADER__TRAITS___INTEGER

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Integer
	: std::bool_constant<xieite::concepts::Integer<Type>> {};
}

#endif
