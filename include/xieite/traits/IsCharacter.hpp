#ifndef XIEITE_HEADER__TRAITS__IS_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_CHARACTER

#	include <type_traits>
#	include "../concepts/Character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsCharacter
	: std::bool_constant<xieite::concepts::Character<Type>> {};
}

#endif
