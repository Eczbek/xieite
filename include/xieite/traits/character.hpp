#ifndef XIEITE_HEADER__TRAITS___CHARACTER
#	define XIEITE_HEADER__TRAITS___CHARACTER

#	include <type_traits>
#	include "../concepts/character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Character
	: std::bool_constant<xieite::concepts::Character<Type>> {};
}

#endif
