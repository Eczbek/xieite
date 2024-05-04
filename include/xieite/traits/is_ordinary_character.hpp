#ifndef XIEITE_HEADER_TRAITS_IS_ORDINARY_CHARACTER
#	define XIEITE_HEADER_TRAITS_IS_ORDINARY_CHARACTER

#	include <type_traits>
#	include "../concepts/ordinary_character.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsOrdinaryCharacter
	: std::bool_constant<xieite::concepts::OrdinaryCharacter<Type_>> {};
}

#endif
