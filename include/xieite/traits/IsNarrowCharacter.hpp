#ifndef XIEITE_HEADER__TRAITS__IS_NARROW_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_NARROW_CHARACTER

#	include <type_traits>
#	include "../concepts/NarrowCharacter.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsNarrowCharacter
	: std::bool_constant<xieite::concepts::NarrowCharacter<Type>> {};
}

#endif
