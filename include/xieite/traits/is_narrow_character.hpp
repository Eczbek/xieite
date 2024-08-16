#ifndef XIEITE_HEADER_TRAITS_IS_NARROW_CHARACTER
#	define XIEITE_HEADER_TRAITS_IS_NARROW_CHARACTER

#	include <type_traits>
#	include "../concepts/narrow_character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsNarrowCharacter
	: std::bool_constant<xieite::concepts::NarrowCharacter<Type>> {};
}

#endif
