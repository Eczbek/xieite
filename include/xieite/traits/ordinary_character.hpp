#ifndef XIEITE_HEADER_TRAITS_ORDINARY_CHARACTER
#	define XIEITE_HEADER_TRAITS_ORDINARY_CHARACTER

#	include <type_traits>
#	include "../concepts/ordinary_character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct OrdinaryCharacter
	: std::bool_constant<xieite::concepts::OrdinaryCharacter<Type>> {};
}

#endif
