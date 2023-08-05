#ifndef XIEITE_HEADER__CONCEPTS__NARROW_CHARACTER
#	define XIEITE_HEADER__CONCEPTS__NARROW_CHARACTER

#	include "../traits/IsNarrowCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept NarrowCharacter = xieite::traits::IsNarrowCharacter<Type>::value;
}

#endif
