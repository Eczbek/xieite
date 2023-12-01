#ifndef XIEITE_HEADER_TRAITS_IS_CHARACTER
#	define XIEITE_HEADER_TRAITS_IS_CHARACTER

#	include <type_traits>
#	include "../concepts/character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsCharacter
	: std::bool_constant<xieite::concepts::Character<Type>> {};
}

#endif
